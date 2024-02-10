#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 corner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0, -1), color),
        VertexFormat(glm::vec3(-length, length, -1), color),
        VertexFormat(glm::vec3(length, length, -1), color),
        VertexFormat(glm::vec3(length, -length, -1), color),
        VertexFormat(glm::vec3(-length, -length, -1), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
                                          1, 0, 2,
                                          2, 0, 3,
                                          3, 0, 4,
                                          4, 0, 1
    };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}
Mesh* object2D::CreateSquareR(
    const std::string& name,
    float length,
    glm::vec3 color)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0, -1), color),
        VertexFormat(glm::vec3(-length, length, -1), color),
        VertexFormat(glm::vec3(length, length, -1), color),
        VertexFormat(glm::vec3(length, -length, -1), color),
        VertexFormat(glm::vec3(-length, -length, -1), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = {
                                          1, 0, 2,
                                          2, 0, 3,
                                          3, 0, 4,
                                          4, 0, 1
    };

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateSquareFrame(
    const std::string& name,
    float length,
    glm::vec3 color)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(-length, length, -1), color),
        VertexFormat(glm::vec3(length, length, -1), color),
        VertexFormat(glm::vec3(length, -length, -1), color),
        VertexFormat(glm::vec3(-length, -length, -1), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices;

        indices = { 0, 1, 2, 3, 0 };
        square->SetDrawMode(GL_LINE_LOOP);
 


    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateHexagon(
const std::string& name,
float length,
glm::vec3 colorFirst,
glm::vec3 colorSecond)
{

    length = length / 2;

    float smallerLength = length * 0.7;

    std::vector<VertexFormat> vertices
    {
    VertexFormat(glm::vec3(-2 * length, 0,  1), colorFirst),
    VertexFormat(glm::vec3(0, 0,  1), colorFirst),
    VertexFormat(glm::vec3(-length, -length * sqrt(3),  1), colorFirst),
    VertexFormat(glm::vec3(length, -length * sqrt(3),  1), colorFirst),
    VertexFormat(glm::vec3(2 * length, 0,  1), colorFirst),
    VertexFormat(glm::vec3(length, length * sqrt(3),  1), colorFirst),
    VertexFormat(glm::vec3(-length, length * sqrt(3),  1), colorFirst),

    VertexFormat(glm::vec3(-2 * smallerLength, 0,  2), colorSecond),
    VertexFormat(glm::vec3(0, 0,  2), colorSecond),
    VertexFormat(glm::vec3(-smallerLength, -smallerLength * sqrt(3),  2), colorSecond),
    VertexFormat(glm::vec3(smallerLength, -smallerLength * sqrt(3),  2), colorSecond),
    VertexFormat(glm::vec3(2 * smallerLength, 0,  2), colorSecond),
    VertexFormat(glm::vec3(smallerLength, smallerLength * sqrt(3),  2), colorSecond),
    VertexFormat(glm::vec3(-smallerLength, smallerLength * sqrt(3),  2), colorSecond)
    };


    Mesh* hexagon = new Mesh(name);
    std::vector<unsigned int> indices = { 6, 1, 0,
                                         0, 1, 2,
                                         2, 1, 3,
                                         3, 1, 4,
                                         4, 1, 5,
                                         5, 1, 6,
        /// small one
        13, 8, 7,
        7, 8, 9,
        9, 8, 10,
        10, 8, 11,
        11, 8, 12,
        12, 8, 13
    };

    hexagon->InitFromData(vertices, indices);
    return hexagon;
}

Mesh* object2D::CreateStar(
    const std::string& name,
    float length,
    glm::vec3 color,
    float zIndex)
{
    float smallerLength = length * 0.7;

    std::vector<VertexFormat> vertices
    {
    VertexFormat(glm::vec3(0, length,  zIndex), color), // 0
    VertexFormat(glm::vec3(0.95 * length, 0.3 * length,  zIndex), color), // 1
    VertexFormat(glm::vec3(0.6 * length, -0.8 * length,  zIndex), color), // 2
    VertexFormat(glm::vec3(0, -0.4 * length,  zIndex), color),// 3
    VertexFormat(glm::vec3(-0.6 * length, -0.8 * length,  zIndex), color), //4
    VertexFormat(glm::vec3(-0.95 * length, 0.3 * length,  zIndex), color), //5
    VertexFormat(glm::vec3(-0.25 * length, 0.3 * length,  zIndex), color), //6
    VertexFormat(glm::vec3(0.25 * length, 0.3 * length,  zIndex), color), //7
    VertexFormat(glm::vec3(0.32 * length, 0,  zIndex), color), //8
    VertexFormat(glm::vec3(0.36 * length, -0.12 * length,  zIndex), color), //9
    VertexFormat(glm::vec3(0, 0,  zIndex), color), //10  centrat in origine
    VertexFormat(glm::vec3(-0.36 * length, -0.12 * length,  zIndex), color), //11
    VertexFormat(glm::vec3(-0.32 * length, 0,  zIndex), color), //12
    };


    Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = {
                                          // star exterior
                                          0, 6, 7,
                                          5, 11, 6,
                                          4, 3, 11,
                                          2, 9, 3,
                                          1, 7, 9,
                                          // star interior
                                          3, 11, 9,
                                          12, 10, 11,
                                           6, 10, 12,
                                           7, 10, 6,
                                           8, 10, 7,
                                           9, 10, 8,
                                           10, 11, 9,
                                           11, 12, 5,
                                           12, 6, 5,
                                           8, 1, 9,
                                           8, 1, 7
                                         };


    star->InitFromData(vertices, indices);
    return star;
}

Mesh* object2D::CreateDiamond(
    const std::string& name,
    float length,
    glm::vec3 color)
{

    std::vector<VertexFormat> vertices
    {
        /// romb basic
    VertexFormat(glm::vec3(0, 4 * length,  0), color),
    VertexFormat(glm::vec3(-2 * length, 0,  0), color),
    VertexFormat(glm::vec3(0, -4 * length,  0), color),
    VertexFormat(glm::vec3(2 * length, 0,  0), color),

    /// extra romb
    VertexFormat(glm::vec3(0, 0.7 * length,  0), color),
    VertexFormat(glm::vec3(0, -0.7 * length,  0), color),
    VertexFormat(glm::vec3(4 * length, 0.7 * length,  0), color),
    VertexFormat(glm::vec3(4 * length, -0.7 * length,  0), color),

    // centrat in origine
    VertexFormat(glm::vec3(0, 0,  0), color)
    };


    Mesh* diamond = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 8,
                                            0, 8, 3,
                                            8, 3, 2,
                                            8, 2, 1,
                                            // dreptunghiul
                                            4, 3, 8,
                                            8, 3, 5,
                                            4, 3, 6,
                                            5, 7, 6
                                             

    };

    diamond->InitFromData(vertices, indices);
    return diamond;
}


Mesh* object2D::CreateRectangle(
    const std::string& name,
    float length,
    float width,
    glm::vec3 color)
{
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0, 1), color),
        VertexFormat(glm::vec3(-width, length, 1), color),
        VertexFormat(glm::vec3(width, length, 1), color),
        VertexFormat(glm::vec3(width, -length, 1), color),
        VertexFormat(glm::vec3(-width, -length, 1), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = {
                                            1, 0, 2,
                                            2, 0, 3,
                                            3, 0, 4,
                                            4, 0, 1
    };

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreateHeart(
    const std::string& name,
    float length,
    glm::vec3 color)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0, 0, 0), color), // 0
        VertexFormat(glm::vec3(-length, 0, 0), color), // 1
        // stanga sus 
        VertexFormat(glm::vec3(-1.05 * length, 0.2 * length, 0), color), // 2
        VertexFormat(glm::vec3(-1.1 * length, 0.5 * length, 0), color), // 3
        VertexFormat(glm::vec3(-length, length, 0), color), // 4
        VertexFormat(glm::vec3(-0.55 * length, 1.25 * length, 0), color), // 5
        VertexFormat(glm::vec3(0, length * 0.85, 0), color), // 6

        // dreapta sus
        VertexFormat(glm::vec3(1.05 * length, 0.2 * length, 0), color), // 7
        VertexFormat(glm::vec3(1.1 * length, 0.5 * length, 0), color), // 8
        VertexFormat(glm::vec3(length, length, 0), color), // 9
        VertexFormat(glm::vec3(0.55 * length, 1.25 * length, 0), color), // 10
        VertexFormat(glm::vec3(0, length * 0.85, 0), color), // 11

        // dreapta jos
        VertexFormat(glm::vec3(0.95 * length, -0.1 * length, 0), color), // 12
        VertexFormat(glm::vec3(0.87 * length, -0.2 * length, 0), color), // 13
        VertexFormat(glm::vec3(0.8 * length, -0.3 * length, 0), color), // 14
        VertexFormat(glm::vec3(0.72 * length, -0.4 * length, 0), color), // 15
        VertexFormat(glm::vec3(0.62 * length, -0.5 * length, 0), color), // 16
        VertexFormat(glm::vec3(0.5 * length, -0.6 * length, 0), color), // 17
        VertexFormat(glm::vec3(0.37 * length, -0.7 * length, 0), color), // 18
        VertexFormat(glm::vec3(0.22 * length, -0.8 * length, 0), color), // 19
        VertexFormat(glm::vec3(0.1 * length, -0.9 * length, 0), color), // 20
        VertexFormat(glm::vec3(0, -length, 0), color), // 21

        // stanga jos
        VertexFormat(glm::vec3(-0.95 * length, -0.1 * length, 0), color), // 22
        VertexFormat(glm::vec3(-0.87 * length, -0.2 * length, 0), color), // 23
        VertexFormat(glm::vec3(-0.8 * length, -0.3 * length, 0), color), // 24
        VertexFormat(glm::vec3(-0.72 * length, -0.4 * length, 0), color), // 25
        VertexFormat(glm::vec3(-0.62 * length, -0.5 * length, 0), color), // 26
        VertexFormat(glm::vec3(-0.5 * length, -0.6 * length, 0), color), // 27
        VertexFormat(glm::vec3(-0.37 * length, -0.7 * length, 0), color), // 28
        VertexFormat(glm::vec3(-0.22 * length, -0.8 * length, 0), color), // 29
        VertexFormat(glm::vec3(-0.1 * length, -0.9 * length, 0), color), // 30
        VertexFormat(glm::vec3(-0, -length, 0), color), // 31
    };

    Mesh* heart = new Mesh(name);
    std::vector<unsigned int> indices = {
        // partea stanga sus
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        // partea dreapta sus
        0, 6, 7,
        0, 7, 8,
        0, 8, 9,
        0, 9, 10,
        0, 10, 11,
        0, 9, 12,
        0, 10, 12,
        0, 8, 12,
        // partea drepta jos
        0, 11, 12,
        0, 12, 13,
        0, 13, 14,
        0, 14, 15,
        0, 15, 16,
        0, 16, 17,
        0, 17, 18,
        0, 18, 19,
        0, 19, 20,
        0, 20, 21,

        // stanga jos
        0, 21, 22,
        0, 22, 23,
        0, 23, 24,
        0, 24, 25,
        0, 25, 26,
        0, 26, 27,
        0, 27, 28,
        0, 28, 29,
        0, 29, 30,
        0, 30, 31,

        0, 1 ,31,
        0, 2, 31,
        0, 3, 31,

        //extra
        2, 3, 5,
        3, 5 ,6,
        4, 6, 2
    };

    heart->InitFromData(vertices, indices);
    return heart;
}

    Mesh* object2D::CreatePresent(
        const std::string& name,
        float length)
    {
        std::vector<VertexFormat> vertices =
        {
            VertexFormat(glm::vec3(0, 0, 4),  glm::vec3(1, 0, 0)), // 0
            VertexFormat(glm::vec3(-length, length / 4, 4), glm::vec3(1, 0, 0)), // 1
            VertexFormat(glm::vec3(length, length / 4, 4), glm::vec3(1, 0, 0)), // 2
            VertexFormat(glm::vec3(length, -length / 4, 4), glm::vec3(1, 0, 0)), // 3
            VertexFormat(glm::vec3(-length, -length / 4, 4), glm::vec3(1, 0, 0)), // 4
            VertexFormat(glm::vec3(-length / 4, length, 4), glm::vec3(1, 0, 0)), // 5
            VertexFormat(glm::vec3(length / 4, length, 4), glm::vec3(1, 0, 0)), // 6
            VertexFormat(glm::vec3(-length / 4, -length, 4), glm::vec3(1, 0, 0)), // 7
            VertexFormat(glm::vec3(length / 4, -length, 4), glm::vec3(1, 0, 0)), // 8
            VertexFormat(glm::vec3(-length, length, 4), glm::vec3(0.314, 0.749, 0)), // 9
            VertexFormat(glm::vec3(length, length, 4), glm::vec3(0.314, 0.749, 0)), // 10
            VertexFormat(glm::vec3(length, -length, 4), glm::vec3(0.314, 0.749, 0)), // 11
            VertexFormat(glm::vec3(-length, -length, 4), glm::vec3(0.314, 0.749, 0)), // 12
            VertexFormat(glm::vec3(0, length * 0.8, 4),  glm::vec3(1, 0, 0)), // 13
            VertexFormat(glm::vec3(length, length * 1.7, 4),  glm::vec3(1, 0, 0)), // 14
            VertexFormat(glm::vec3(length / 2, length * 1.7, 4), glm::vec3(1, 0, 0)), // 15
            VertexFormat(glm::vec3(-length, 1.7 * length, 4),  glm::vec3(1, 0, 0)), // 16
            VertexFormat(glm::vec3(-length / 2, 1.7 * length, 4),  glm::vec3(1, 0, 0)) // 17
        };

        Mesh* present = new Mesh(name);
        std::vector<unsigned int> indices = {
                                                1, 3, 4,
                                                1, 3, 2,
                                                5, 8, 7,
                                                5, 8, 6,

                                                // verde
                                                9, 10, 11,
                                                9, 11, 12,

                                                // funda
                                                16, 17, 13,
                                                13, 14, 15
        };

        present->InitFromData(vertices, indices);
        return present;
    }