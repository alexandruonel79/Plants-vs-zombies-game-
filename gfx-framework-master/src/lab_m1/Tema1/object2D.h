#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{
    // don t touch it
    Mesh* CreateSquare(const std::string &name, glm::vec3 corner, float length, glm::vec3 color, bool fill = false);

    Mesh* CreateSquareR(const std::string& name, float length, glm::vec3 color);

    Mesh* CreateSquareFrame(const std::string& name, float length, glm::vec3 color);

    Mesh* CreateHexagon(const std::string& name, float length, glm::vec3 colorFirst, glm::vec3 colorSecond);

    Mesh* CreateStar(const std::string& name, float length, glm::vec3 color, float zIndex);

    Mesh* CreateDiamond(const std::string& name, float length, glm::vec3 color);

    Mesh* CreateRectangle(const std::string& name, float length, float width, glm::vec3 color);

    Mesh* CreateHeart(const std::string& name, float length, glm::vec3 color);

    Mesh* CreatePresent(const std::string& name, float length);
}
