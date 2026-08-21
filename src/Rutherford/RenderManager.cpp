//
// Created by corvaos on 8/17/26.
//

#include "Rutherford/RenderManager.h"

RenderManager::RenderManager(const std::string& name, const int& windowWidth, const int& windowHeight) :
  window(vaos::renderer::Window(name, windowWidth, windowHeight))
{
  vaos::renderer::Shader::setAssetLocationPrefix("../assets/");
  vaos::renderer::Material("meshVertexShader.glsl", "heliumFragmentShader.glsl");
  vaos::renderer::Material(vaos::renderer::Shader::compileShader("meshVertexShader.glsl", "goldFragmentShader.glsl"));
}

void RenderManager::addRenderParticle(const vaos::numerics::Vector3& position, const double mass, const int id)
{
  window.objects.emplace_back(vaos::renderer::MeshFactory::getMesh("circle100"),
                              *vaos::renderer::Material::materials[id]);
}

void RenderManager::assignTransforms(const std::vector<vaos::numerics::Transform>& transforms)
{
  for (int i = 0; i < transforms.size(); i++)
  {
    window.objects[i].transform = transforms[i];
  }
}

void RenderManager::assignTransforms(const vaos::numerics::Transform& transform, const int id)
{
  window.objects[id].transform = transform;
}

void RenderManager::drawAll()
{
  window.render();
}
