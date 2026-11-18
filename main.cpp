#include <iostream>

#include <fstream>

// char* (char) {

// }
// void Reverce(int )

int main(int argc, char** argv) {
    // std::cout << argv[0] << " " << argc;

    if (argc != 4) {
        std::cout << "correct input: ./app IMAGE COMMANDS OUTPUT" << std::endl;
        return 1;
    }
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cout << "cannot open input file" << std::endl;
        return 1;
    }


    
    int height = 0;
    int width = 0;
    input >> height >> width;

    char* image = new char[height * width];
    for (int i = 0; i < height * width; i++) {
        image[i] = 0;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c = 0;
            input >> c;
            image[i * width + j] = c;
        }
    }
    input.close();
    const char* commands = argv[2];



    for (int k = 0; commands[k] != '\0'; k++) {
        char c = commands[k];
        char* a = new char[height * width];
        for (int i = 0; i < height * width; i++) {
            a[i] = 0;
        }

        if (c == 'H') {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    a[i * width + j] = image[i * width + (width - 1 - j)];
                }
            }
        } else if (c == 'V') {
            for (int i = 0; i < height; i++) {

            }
        } else if (c == 'R') {
            int b = height;
            height = width;
            width = b;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    a[i * width + j] = image[(width - 1 - j) * height + i];
                }
            }
        }

        delete[] image;
        image = a;
    }



    std::ofstream output(argv[3]);
    if (!output.is_open()) {
        std::cout << "cannot open output file" << std::endl;
        delete[] image;
        return 1;
    }



    output << height << " " << width << "\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            output << image[i * width + j];
        }
        output << "\n";
    }
    if (output.fail()) {
        std::cout << "cannot write output" << std::endl;
        delete[] image;
        return 1;
    }

    output.close();
    delete[] image;
    return 0;
}
//./app image.txt "RHV" output.txt