#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shape {
public:
    virtual void draw() const = 0;
    virtual void setColor(GLfloat r, GLfloat g, GLfloat b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

protected:
    GLfloat color[3] = { 1.0f, 1.0f, 1.0f }; // Default color is white
};


class Cube : public Shape {
public:
    Cube(float size) : size(size), position(glm::vec3(0.0f, 0.0f, 0.0f)) {}

    void setPosition(const glm::vec3& newPosition) {
        position = newPosition;
    }

    void draw() const override {
        // Front face
        glColor3fv(frontColor);
        glBegin(GL_QUADS);
        glVertex3f(-size / 2, -size / 2, size / 2);
        glVertex3f(size / 2, -size / 2, size / 2);
        glVertex3f(size / 2, size / 2, size / 2);
        glVertex3f(-size / 2, size / 2, size / 2);
        glEnd();

        // Back face
        glColor3fv(backColor);
        glBegin(GL_QUADS);
        glVertex3f(-size / 2, -size / 2, -size / 2);
        glVertex3f(size / 2, -size / 2, -size / 2);
        glVertex3f(size / 2, size / 2, -size / 2);
        glVertex3f(-size / 2, size / 2, -size / 2);
        glEnd();

        // Left face
        glColor3fv(leftColor);
        glBegin(GL_QUADS);
        glVertex3f(-size / 2, -size / 2, size / 2);
        glVertex3f(-size / 2, size / 2, size / 2);
        glVertex3f(-size / 2, size / 2, -size / 2);
        glVertex3f(-size / 2, -size / 2, -size / 2);
        glEnd();

        // Right face
        glColor3fv(rightColor);
        glBegin(GL_QUADS);
        glVertex3f(size / 2, -size / 2, size / 2);
        glVertex3f(size / 2, size / 2, size / 2);
        glVertex3f(size / 2, size / 2, -size / 2);
        glVertex3f(size / 2, -size / 2, -size / 2);
        glEnd();

        // Top face
        glColor3fv(topColor);
        glBegin(GL_QUADS);
        glVertex3f(-size / 2, size / 2, size / 2);
        glVertex3f(size / 2, size / 2, size / 2);
        glVertex3f(size / 2, size / 2, -size / 2);
        glVertex3f(-size / 2, size / 2, -size / 2);
        glEnd();

        // Bottom face
        glColor3fv(bottomColor);
        glBegin(GL_QUADS);
        glVertex3f(-size / 2, -size / 2, size / 2);
        glVertex3f(size / 2, -size / 2, size / 2);
        glVertex3f(size / 2, -size / 2, -size / 2);
        glVertex3f(-size / 2, -size / 2, -size / 2);
        glEnd();
    }

    void setFrontColor(GLfloat r, GLfloat g, GLfloat b) {
        frontColor[0] = r;
        frontColor[1] = g;
        frontColor[2] = b;
    }

    void setBackColor(GLfloat r, GLfloat g, GLfloat b) {
        backColor[0] = r;
        backColor[1] = g;
        backColor[2] = b;
    }

    void setLeftColor(GLfloat r, GLfloat g, GLfloat b) {
        leftColor[0] = r;
        leftColor[1] = g;
        leftColor[2] = b;
    }

    void setRightColor(GLfloat r, GLfloat g, GLfloat b) {
        rightColor[0] = r;
        rightColor[1] = g;
        rightColor[2] = b;
    }

    void setTopColor(GLfloat r, GLfloat g, GLfloat b) {
        topColor[0] = r;
        topColor[1] = g;
        topColor[2] = b;
    }

    void setBottomColor(GLfloat r, GLfloat g, GLfloat b) {
        bottomColor[0] = r;
        bottomColor[1] = g;
        bottomColor[2] = b;
    }

private:
    GLfloat frontColor[3] = { 1.0f, 0.0f, 0.0f };
    GLfloat backColor[3] = { 0.0f, 1.0f, 0.0f };
    GLfloat leftColor[3] = { 0.0f, 0.0f, 1.0f };
    GLfloat rightColor[3] = { 1.0f, 1.0f, 0.0f };
    GLfloat topColor[3] = { 1.0f, 0.0f, 1.0f };
    GLfloat bottomColor[3] = { 0.0f, 1.0f, 1.0f };
    glm::vec3 position;

    float size;
};

class RectangularPrism : public Shape {
public:
    RectangularPrism(float length, float width, float height) : length(length), width(width), height(height), position(glm::vec3(0.0f, 0.0f, 0.0f)) {}

    void setPosition(const glm::vec3& newPosition) {
        position = newPosition;
    }

    void draw() const override {
        // Front face
        glColor3fv(frontColor);
        glBegin(GL_QUADS);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glVertex3f(length / 2, -width / 2, height / 2);
        glVertex3f(length / 2, width / 2, height / 2);
        glVertex3f(-length / 2, width / 2, height / 2);
        glEnd();

        // Back face
        glColor3fv(backColor);
        glBegin(GL_QUADS);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glVertex3f(length / 2, -width / 2, -height / 2);
        glVertex3f(length / 2, width / 2, -height / 2);
        glVertex3f(-length / 2, width / 2, -height / 2);
        glEnd();

        // Left face
        glColor3fv(leftColor);
        glBegin(GL_QUADS);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glVertex3f(-length / 2, width / 2, height / 2);
        glVertex3f(-length / 2, width / 2, -height / 2);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glEnd();

        // Right face
        glColor3fv(rightColor);
        glBegin(GL_QUADS);
        glVertex3f(length / 2, -width / 2, height / 2);
        glVertex3f(length / 2, width / 2, height / 2);
        glVertex3f(length / 2, width / 2, -height / 2);
        glVertex3f(length / 2, -width / 2, -height / 2);
        glEnd();

        // Top face
        glColor3fv(topColor);
        glBegin(GL_QUADS);
        glVertex3f(-length / 2, width / 2, height / 2);
        glVertex3f(length / 2, width / 2, height / 2);
        glVertex3f(length / 2, width / 2, -height / 2);
        glVertex3f(-length / 2, width / 2, -height / 2);
        glEnd();

        // Bottom face
        glColor3fv(bottomColor);
        glBegin(GL_QUADS);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glVertex3f(length / 2, -width / 2, height / 2);
        glVertex3f(length / 2, -width / 2, -height / 2);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glEnd();
    }

    void setFrontColor(GLfloat r, GLfloat g, GLfloat b) {
        frontColor[0] = r;
        frontColor[1] = g;
        frontColor[2] = b;
    }

    void setBackColor(GLfloat r, GLfloat g, GLfloat b) {
        backColor[0] = r;
        backColor[1] = g;
        backColor[2] = b;
    }

    void setLeftColor(GLfloat r, GLfloat g, GLfloat b) {
        leftColor[0] = r;
        leftColor[1] = g;
        leftColor[2] = b;
    }

    void setRightColor(GLfloat r, GLfloat g, GLfloat b) {
        rightColor[0] = r;
        rightColor[1] = g;
        rightColor[2] = b;
    }

    void setTopColor(GLfloat r, GLfloat g, GLfloat b) {
        topColor[0] = r;
        topColor[1] = g;
        topColor[2] = b;
    }

    void setBottomColor(GLfloat r, GLfloat g, GLfloat b) {
        bottomColor[0] = r;
        bottomColor[1] = g;
        bottomColor[2] = b;
    }

private:
    GLfloat frontColor[3] = { 1.0f, 0.0f, 0.0f };
    GLfloat backColor[3] = { 0.0f, 1.0f, 0.0f };
    GLfloat leftColor[3] = { 0.0f, 0.0f, 1.0f };
    GLfloat rightColor[3] = { 1.0f, 1.0f, 0.0f };
    GLfloat topColor[3] = { 1.0f, 0.0f, 1.0f };
    GLfloat bottomColor[3] = { 0.0f, 1.0f, 1.0f };
    glm::vec3 position;

    float length, width, height;
};

RectangularPrism rectangularPrism(1.5f, 2.0f, 1.0f); // Początkowe rozmiary prostopadłościanu


class Pyramid : public Shape {
public:
    Pyramid(float size) : size(size), position(glm::vec3(0.0f, 0.0f, 0.0f)) {}

    void setPosition(const glm::vec3& newPosition) {
        position = newPosition;
    }

    void draw() const override {
        // Base
        glColor3fv(baseColor);
        glBegin(GL_QUADS);
        glVertex3f(-size / 2, -size / 2, -size / 2);
        glVertex3f(size / 2, -size / 2, -size / 2);
        glVertex3f(size / 2, -size / 2, size / 2);
        glVertex3f(-size / 2, -size / 2, size / 2);
        glEnd();

        // Front face
        glColor3fv(frontColor);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, size / 2, 0.0f);
        glVertex3f(-size / 2, -size / 2, size / 2);
        glVertex3f(size / 2, -size / 2, size / 2);
        glEnd();

        // Back left face
        glColor3fv(backLeftColor);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, size / 2, 0.0f);
        glVertex3f(-size / 2, -size / 2, -size / 2);
        glVertex3f(-size / 2, -size / 2, size / 2);
        glEnd();

        // Back right face
        glColor3fv(backRightColor);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, size / 2, 0.0f);
        glVertex3f(size / 2, -size / 2, -size / 2);
        glVertex3f(size / 2, -size / 2, size / 2);
        glEnd();
    }

    void setBaseColor(GLfloat r, GLfloat g, GLfloat b) {
        baseColor[0] = r;
        baseColor[1] = g;
        baseColor[2] = b;
    }

    void setFrontColor(GLfloat r, GLfloat g, GLfloat b) {
        frontColor[0] = r;
        frontColor[1] = g;
        frontColor[2] = b;
    }

    void setBackLeftColor(GLfloat r, GLfloat g, GLfloat b) {
        backLeftColor[0] = r;
        backLeftColor[1] = g;
        backLeftColor[2] = b;
    }

    void setBackRightColor(GLfloat r, GLfloat g, GLfloat b) {
        backRightColor[0] = r;
        backRightColor[1] = g;
        backRightColor[2] = b;
    }

private:
    GLfloat baseColor[3] = { 1.0f, 1.0f, 1.0f };
    GLfloat frontColor[3] = { 1.0f, 0.0f, 0.0f };
    GLfloat backLeftColor[3] = { 0.0f, 1.0f, 0.0f };
    GLfloat backRightColor[3] = { 0.0f, 0.0f, 1.0f };
    glm::vec3 position;

    float size;
};

float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 5.0f;

Cube cube(1.0f);      // Początkowy rozmiar kostki
Pyramid pyramid(1.0f); // Początkowy rozmiar piramidy

void processInput(GLFWwindow* window) {
    const float cameraSpeed = 0.001f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraZ -= cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraZ += cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraX -= cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraX += cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        cameraY -= cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        cameraY += cameraSpeed;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        // Zmiana koloru kostki po kliknięciu lewego przycisku myszy
        cube.setFrontColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        cube.setBackColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        cube.setLeftColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        cube.setRightColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        cube.setTopColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        cube.setBottomColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        // Zmiana koloru piramidy po kliknięciu lewego przycisku myszy
        pyramid.setBaseColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        pyramid.setFrontColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        pyramid.setBackLeftColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        pyramid.setBackRightColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        // Zmiana koloru prostopadłościanu po kliknięciu lewego przycisku myszy
        rectangularPrism.setFrontColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        rectangularPrism.setBackColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        rectangularPrism.setLeftColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        rectangularPrism.setRightColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        rectangularPrism.setTopColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);

        rectangularPrism.setBottomColor(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);
    }
}



void renderScene(const Shape& shape1, const Shape& shape2, const Shape& shape3) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Render cube
    glm::mat4 projection = glm::perspective(glm::radians(30.0f), 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection));

    glm::mat4 view = glm::lookAt(glm::vec3(cameraX - 2.0f, cameraY, cameraZ + 5.0f), glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    GLfloat* viewMatrixPtr = glm::value_ptr(view);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(viewMatrixPtr);

    shape1.draw();

    // Render pyramid
    view = glm::lookAt(glm::vec3(cameraX + 1.0f, cameraY, cameraZ + 4.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    viewMatrixPtr = glm::value_ptr(view);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(viewMatrixPtr);

    shape2.draw();

    // Render rectangular prism
    view = glm::lookAt(glm::vec3(cameraX + 4.0f, cameraY, cameraZ + 6.0f), glm::vec3(0.0f, 0.0f, 4.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    viewMatrixPtr = glm::value_ptr(view);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(viewMatrixPtr);

    shape3.draw();

    glFlush();
}


int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Cube", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);

    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        processInput(window);

        // Ustawienia początkowe pozycji obiektów
        cube.setPosition(glm::vec3(-5.0f, 10.0f, 100.0f));
        pyramid.setPosition(glm::vec3(700.0f, 25.0f, 200.0f));
        rectangularPrism.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));


        renderScene(cube, pyramid, rectangularPrism);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
