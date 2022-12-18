#pragma once

#ifndef _glfw3_h_
class GLFWwindow;
#endif

class Window {
    GLFWwindow* m_windowPtr;
    const char* m_title;
    struct Size {
        int width;
        int height;
    } m_size;
    //bool m_fullscreen;
    
public:
    Window(const char* title="None", Size size = {640, 480});
    bool update();
    void setSize(int w, int h);
    Size getSize();
    void setPos(int w, int h);
    void onResize(int w, int h);
    GLFWwindow* getGlfwWindowPtr() const;
    void toggleFullScreen();
    ~Window();
};
