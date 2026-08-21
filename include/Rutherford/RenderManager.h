//
// Created by corvaos on 8/17/26.
//

#ifndef RUTHERFORD_RENDERMANAGER_H
#define RUTHERFORD_RENDERMANAGER_H

#include "vaos/renderer/Window.h"
#include "vaos/renderer/Mesh/MeshFactory.h"

#include "vaos/renderer/RenderObject.h"
#include "vaos/renderer/Material.h"

class RenderManager
{
public:
  vaos::renderer::Window window;

  RenderManager(const std::string& name, const int& windowWidth, const int& windowHeight);

  void addRenderParticle(const vaos::numerics::Vector3& position, double mass, int id);

  void assignTransforms(const std::vector<vaos::numerics::Transform>& transforms);

  void assignTransforms(const vaos::numerics::Transform& transform, int id);

  void drawAll();
};

#endif //RUTHERFORD_RENDERMANAGER_H
