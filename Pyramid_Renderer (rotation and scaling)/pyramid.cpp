#include "pyramid.h"
#include "Renderer3D.h"
#include <iostream>
#include <vector>
#include <SDL.h>
#include <cmath>

// Creates an array of points for a rotated pyramid
std::vector<Point3D> points{
    Point3D{0, 0, 1},                   // Apex
    Point3D{-1, -1, -1},                // Base vertex 1
    Point3D{1, -1, -1},                 // Base vertex 2
    Point3D{1, 1, -1},                  // Base vertex 3
    Point3D{-1, 1, -1}                  // Base vertex 4
};

// Angle of rotation around the x-axis (pitch) in radians
double pitch = 0.3;

// Angle of rotation around the y-axis (yaw) in radians
double yaw = 0.2;

// Angle of rotation around the z-axis (roll) in radians
double roll = 0.1;

// Creates an array of edges for a pyramid (This holds indices referencing the points array)
std::vector<Edge> edges{
    Edge{0, 1}, // Edge from apex to base vertex 1
    Edge{0, 2}, // Edge from apex to base vertex 2
    Edge{0, 3}, // Edge from apex to base vertex 3
    Edge{0, 4}, // Edge from apex to base vertex 4
    Edge{1, 2}, // Edge connecting base vertex 1 to base vertex 2
    Edge{2, 3}, // Edge connecting base vertex 2 to base vertex 3
    Edge{3, 4}, // Edge connecting base vertex 3 to base vertex 4
    Edge{4, 1}  // Edge connecting base vertex 4 to base vertex 1
};


/*
//default C++ function
int main(int argc, char* argv[])
{
    //creating a window and a renderer
    SDL_Window* window;
    SDL_Renderer* renderer;

    //creates a centered window with 960 width and 540 height
    window = SDL_CreateWindow("Pyramid Renderer by Moses Onerhime", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;

    // Apply rotations around x, y, and z axes
    for (Point3D& point : points) {
        // Rotation around the x-axis (pitch)
        double temp_y = point.y;
        point.y = temp_y * cos(pitch) - point.z * sin(pitch);
        point.z = temp_y * sin(pitch) + point.z * cos(pitch);

        // Rotation around the y-axis (yaw)
        double temp_x = point.x;
        point.x = temp_x * cos(yaw) + point.z * sin(yaw);
        point.z = -temp_x * sin(yaw) + point.z * cos(yaw);

        // Rotation around the z-axis (roll)
        temp_x = point.x;
        point.x = temp_x * cos(roll) - point.y * sin(roll);
        point.y = temp_x * sin(roll) + point.y * cos(roll);
    }


    //Creating an instance of the the Renderer3D class
    Renderer3D render3D(window, renderer, points, edges);

    while (running)
    {
        //if the quit button is pressed, the loop breaks
        if (SDL_QuitRequested()) { running = false; break; }

       

        //Calls the function created in the Renderer3D class (render 3D is an instance of the class defined above)
        render3D.render();
      
    }


    /*
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL initialization succeeded!";
    }

    std::cin.get();
    return 0;
    */


    //return 0;
//}
