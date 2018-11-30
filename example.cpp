#include<GLEWCore/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

void draw()
{
    constexpr GLfloat clear_color[4]={0,0,0,1};

    glClearBufferfv(GL_COLOR,0,clear_color);
}

void output_ogl_info()
{
    std::cout<<"GLFW Version: "<<glfwGetVersionString()<<std::endl;
    std::cout<<"GLEWCore Version: "<<glewGetString(GLEW_VERSION)<<std::endl<<std::endl;

    std::cout<<"Vendor:     "<<glGetString(GL_VENDOR)<<std::endl;
    std::cout<<"Renderer:   "<<glGetString(GL_RENDERER)<<std::endl;
    std::cout<<"Version:    "<<glGetString(GL_VERSION)<<std::endl;

    GLint n=0;

    glGetIntegerv(GL_NUM_EXTENSIONS, &n);

    std::cout<<"Extensions:"<<std::endl;

    for (GLint i=0; i<n; i++)
        std::cout<<"            "<<i<<" : "<<glGetStringi(GL_EXTENSIONS,i)<<std::endl;
}

void glfw_error_callback(int err,const char *desc)
{
    std::cerr<<"glfw return error["<<err<<"] <<"<<desc<<std::endl;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwSetErrorCallback(glfw_error_callback);

    glfwWindowHint(GLFW_OPENGL_PROFILE,         GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,  true);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,  3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,  3);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewInit();
    output_ogl_info();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glewTerminate();        // Added GLEWCore API, which will cause memory leaks when not used
    glfwTerminate();
    return 0;
}
