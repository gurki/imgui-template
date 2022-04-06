#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <cstdio>


static void glfw_error_callback( int error, const char* description ) {
    fprintf( stderr, "GLFW Error %d: %s\n", error, description );
}

int main( int, char** )
{
    // Setup window
    glfwSetErrorCallback( glfw_error_callback );

    if ( ! glfwInit() ) {
        return 1;
    }

    const char* glsl_version = "#version 130";
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow( 1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL );

    if ( window == NULL ) {
        return 1;
    }

    glfwMakeContextCurrent( window );
    glfwSwapInterval( 1 ); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL( window, true );
    ImGui_ImplOpenGL3_Init( glsl_version );

    // Load Fonts
    io.Fonts->AddFontFromFileTTF( "../res/fonts/Roboto-Medium.ttf", 16.0f );

    // Our state
    ImVec4 clear_color = ImVec4( 0.45f, 0.55f, 0.60f, 1.00f );

    // Main loop
    while ( ! glfwWindowShouldClose( window ) )
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin( "Hello, world!" );                          // Create a window called "Hello, world!" and append into it.
            ImGui::Text( "This is some useful text." );               // Display some text (you can use a format strings too)
            ImGui::SliderFloat( "float", &f, 0.0f, 1.0f );            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3( "clear color", (float*)&clear_color ); // Edit 3 floats representing a color

            if ( ImGui::Button( "Button" ) ) {                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            }

            ImGui::SameLine();
            ImGui::Text( "counter = %d", counter );
            ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate );
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize( window, &display_w, &display_h );
        glViewport( 0, 0, display_w, display_h );
        glClearColor( clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w );
        glClear( GL_COLOR_BUFFER_BIT );
        ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

        glfwSwapBuffers( window );
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow( window );
    glfwTerminate();

    return 0;
}
