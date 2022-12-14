#include <GLFW/glfw3.h>

#include <gezzy/input.hpp>
//#include <gezzy/window.hpp>
#include <cpputils/types.hpp>

static u8 keys[512];

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    keys[key] = action;
}
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        keys[MOUSE_LEFT] = action;
    } else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        keys[MOUSE_RIGHT] = action;
    }
}

Input::Input(Window* window) {
    GLFWwindow* windowptr = window->getGlfwWindowPtr();
    glfwSetKeyCallback(windowptr, key_callback);
    glfwSetMouseButtonCallback(windowptr, mouse_button_callback);
}

bool Input::getKey(int key) {
    return keys[key];
}

bool Input::getKeyDown(int key) {
    auto& k = keys[key];
    bool pressed = k == 1;
    if (pressed) {
        k++;
    }

    return pressed;
}

