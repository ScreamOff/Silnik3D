#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Primitive {
public:
    virtual void draw() const = 0;
    virtual void transform() = 0;
};

class ColoredCube : public Primitive {
private:
    float size;
    glm::vec3 color;

public:
    ColoredCube(float s, const glm::vec3& c) : size(s), color(c) {}

    void draw() const override {
        glBegin(GL_QUADS);
        glColor3f(color.r, color.g, color.b);

        // Front
        glVertex3f(-size, -size, size);
        glVertex3f(size, -size, size);
        glVertex3f(size, size, size);
        glVertex3f(-size, size, size);

        // Back
        glVertex3f(-size, -size, -size);
        glVertex3f(size, -size, -size);
        glVertex3f(size, size, -size);
        glVertex3f(-size, size, -size);

        // Left
        glVertex3f(-size, -size, -size);
        glVertex3f(-size, -size, size);
        glVertex3f(-size, size, size);
        glVertex3f(-size, size, -size);

        // Right
        glVertex3f(size, -size, -size);
        glVertex3f(size, -size, size);
        glVertex3f(size, size, size);
        glVertex3f(size, size, -size);

        // Top
        glVertex3f(-size, size, -size);
        glVertex3f(size, size, -size);
        glVertex3f(size, size, size);
        glVertex3f(-size, size, size);

        // Bottom
        glVertex3f(-size, -size, -size);
        glVertex3f(size, -size, -size);
        glVertex3f(size, -size, size);
        glVertex3f(-size, -size, size);
        glEnd();
    }

    void transform() override {
        // Implementacja transformacji geometrycznych dla sześcianu (opcjonalne)
    }
};

class GraphicsEngine {
private:
    GLFWwindow* window;

public:
    GraphicsEngine(GLFWwindow* w) : window(w) {}

    void handleKeyboardInput(int key, int scancode, int action, int mods) {
        // Obsługa klawiatury (opcjonalne)
    }

    void handleMouseInput(double xpos, double ypos) {
        // Obsługa myszy (opcjonalne)
    }

    void update() {
        // Aktualizacja logiki gry (opcjonalne)
    }

    void draw(Primitive& primitive) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        primitive.transform();
        primitive.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
};

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    GraphicsEngine* engine = static_cast<GraphicsEngine*>(glfwGetWindowUserPointer(window));
    engine->handleKeyboardInput(key, scancode, action, mods);
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    GraphicsEngine* engine = static_cast<GraphicsEngine*>(glfwGetWindowUserPointer(window));
    engine->handleMouseInput(xpos, ypos);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Graphics Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        glfwTerminate();
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    GraphicsEngine engine(window);

    glfwSetWindowUserPointer(window, &engine);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, mouseCallback);

    // Czerwona kostka o rozmiarze 2
    ColoredCube redCube(2.0f, glm::vec3(1.0f, 0.0f, 0.0f));

    while (!glfwWindowShouldClose(window)) {
        engine.update();
        engine.draw(redCube);
    }

    glfwTerminate();
    return 0;
}
