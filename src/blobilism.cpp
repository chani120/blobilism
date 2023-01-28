#include <iostream>
#include <vector>
#include "tinygl-cpp.h"
using namespace tinygl;

    struct colors {
        float red;
        float green;
        float blue;
        float transparency;
    };
    struct circvar {
        float x;
        float y;
        float size;
    };


    class MyWindow : public Window {
    public:
        MyWindow(int w, int h) : Window(w, h) {}

        void setup() override {
            std::cout << "Window size: " << width() << ", " << height() << std::endl;
        }

        virtual void mouseMotion(int x, int y, int dx, int dy) {
            if (mouseIsDown(GLFW_MOUSE_BUTTON_LEFT)) {
                // todo: store a circle with the current color, size, x, y
                var.x = x;
                var.y = y;
                var.size = circle_size;
                selected_color.transparency = transparency_level;
                drawing_color.push_back(selected_color);
                drawing.push_back(var);
  
                std::cout << "Motion" << x << "" << y << std::endl;
            }
        }

        

        virtual void mouseDown(int button, int mods) {
            if (button == GLFW_MOUSE_BUTTON_LEFT) {
                // todo: check if user clicked a color 
                float mx = mouseX();  // current mouse pos x
                float my = mouseY();  // current mouse pos y
                float distance; 

                distance = sqrt(pow(2, double(mx - 40)) + pow(2, double(my - 35)));
                if (distance < 30) {
                    selected_color.red = 215.0f/255.0f;
                    selected_color.green = 181.0f/255.0f;
                    selected_color.blue = 88.0f/255.0f;
                }
                    
                else {
                    distance = sqrt(pow(2, double(mx - 110)) + pow(2, double(my - 35)));
                    if (distance < 30) {
                        selected_color.red = 41.0f/255.0f;
                        selected_color.green = 183.0f/255.0f;
                        selected_color.blue = 219.0f/255.0f;
                                       }
                    else {
                        distance = sqrt(pow(2, double(mx - 180)) + pow(2, double(my - 35)));
                        if (distance < 30) {
                            selected_color.red = 199.0f/255.0f;
                            selected_color.green = 147.0f/255.0f;
                            selected_color.blue = 212.0f/255.0f;
                                                    }
                        else {
                            distance = sqrt(pow(2, double(mx - 250)) + pow(2, double(my - 35)));
                            if (distance < 30) {
                                selected_color.red = 149.0f/255.0f;
                                selected_color.green = 171.0f/255.0f;
                                selected_color.blue = 88.0f/255.0f;
                                                         }
                            else {
                                distance = sqrt(pow(2, double(mx - 320)) + pow(2, double(my - 35)));
                                if (distance < 30) {
                                    selected_color.red = 191.0f/255.0f;
                                    selected_color.green = 91.0f/255.0f;
                                    selected_color.blue = 91.0f/255.0f;
                                                                   }
                            }
                        }
                    }
                }
            }

        }
            
        

        void keyDown(int key, int mods) {
            if (key == GLFW_KEY_UP) {
                // increase size of circle
                circle_size = circle_size + 1;
            }
            else if (key == GLFW_KEY_DOWN) {
                // decrease size of circle
                if (circle_size < 2) {
                    circle_size = circle_size;
                }
                else {
                    circle_size = circle_size - 1;
                    std::cout << "Window size: " << key << ", " << circle_size << std::endl;
                }
            }
            else if (key == GLFW_KEY_LEFT) {
                // decrease alpha
                if (transparency_level <= 0.1) {
                    transparency_level = transparency_level;
                }
                else {
                    transparency_level = transparency_level - 0.1;
                }
                std::cout << "Window size: " << key << ", " << transparency_level << std::endl;
            }
            else if (key == GLFW_KEY_RIGHT) {
                // increase alpha
                if (transparency_level <= 0.1) {
                    transparency_level = transparency_level;
                }
                else{
                transparency_level = transparency_level + 0.1;
                }
            }
            else if (key == GLFW_KEY_C) {
                // clear vector of circles
                drawing.clear();
                drawing_color.clear();

            }
        }

        void draw() override {
            background(0.95f, 0.95f, 0.95f); // parameters: r, g, b

            color(1.0f, 0.5f, 0.5f);
            circle(width() * 0.5f, height() * 0.5, circle_size);

            // todo : draw pallet
            color(0.1f, 0.1f, 0.1f);
            square(width() / 2.0f, 35, width(), 70);

            struct circvar cir = { 40, 35, 70 };
            struct colors col = { 215.0f/255.0f, 181.0f/255.0f, 88.0f/255.0f};
            pal.push_back(cir);
            pallet_color.push_back(col);
            cir.x = 110;
            col.red = 41.0f/255.0f;
            col.green = 183.0f/255.0f;
            col.blue = 219.0f/255.0f;
            pal.push_back(cir);
            pallet_color.push_back(col);
            cir.x = 180;
            col.red = 199.0f/255.0f;
            col.green = 147.0f/255.0f;
            col.blue = 212.0f/255.0f;
            pal.push_back(cir);
            pallet_color.push_back(col);
            cir.x = 250;
            col.red = 149.0f/255.0f;
            col.green = 171.0f/255.0f;
            col.blue = 88.0f/255.0f;
            pal.push_back(cir);
            pallet_color.push_back(col);
            cir.x = 320;
            col.red = 191.0f/255.0f;
            col.green = 91.0f/255.0f;
            col.blue = 91.0f/255.0f;
            pal.push_back(cir);
            pallet_color.push_back(col);
            for (int i = 0; i < pal.size(); i++) {
                color(pallet_color[i].red, pallet_color[i].green, pallet_color[i].blue);
                circle(pal[i].x, pal[i].y, pal[i].size);
            }
            for (int i = 0; i < drawing.size(); i++) {
                color(drawing_color[i].red, drawing_color[i].green, drawing_color[i].blue,drawing_color[i].transparency);
                circle(drawing[i].x, drawing[i].y, drawing[i].size);
            }
        }
        private:

            // todo: create member variables for 
            // current circle size
            // current transparencyparency
            // current color
            // list of circles to draw each frame
            // color pallet
            float circle_size = 50;
            float transparency_level = 1;
            struct colors selected_color = { 215,181,88};
            struct circvar var;
            std::vector<colors> pallet_color;
            std::vector<circvar> pal;

            //for drawing color an pallet
            std::vector<circvar> drawing;
            std::vector<colors> drawing_color;
        };

        int main() {
            MyWindow window(500, 500);
            window.run();
        }