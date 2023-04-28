/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** WrapperTest.cpp
*/

#include <iostream>
#include <libconfig.h++>
#include "ConfigWrapper.hpp"

using namespace Raytracer::Scenes;
/*
 * Exemple d'un code récupérant les informations concernant la résolution dans le fichier testScene.config
 */
int main(int ac, char **av)
{
    ConfigWrapper test;

    test.readFile("./testScene.config");
    std::shared_ptr<SceneConfig> sceneConfig = test.getScene();

    std::cout << sceneConfig->getSetting("camera.resolution") << std::endl;

    for (int i = 0; i < sceneConfig->getLength(); i++) {

        int s = sceneConfig->getSettingValue<int>(i);
        std::cout << i << " == " << s << std::endl;
    }

}