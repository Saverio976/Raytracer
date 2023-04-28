#include <iostream>
#include <libconfig.h++>
#include "ConfigWrapper.hpp"

using namespace Raytracer::Scenes;
/*
 * Exemple d'un code récupérant les informations concernant les sphères dans le fichier testScene.config
 */
int main(int ac, char **av) {
    ConfigWrapper test;
    char keys[5] = "xyzr";
    char color_keys[4] = "rgb";

    test.readFile("./testScene.config");

    std::shared_ptr<SettingWrapper> setting = test.getScene();

    //récupération de l'objet contenant les sphères
    setting->getSetting("primitives.spheres");
    //parsing des deux sphères
    for (int i = 0; i < setting->getLength(); i++) {
        //récupération coordonnées :
        std::cout << "sphere[" << i << "]" << std::endl << "\tcoords: " << std::endl << "\t\t";
        for (int j = 0; j < 4; j++)
            std::cout << keys[j] << " = " << static_cast<int>((*setting)[i][j]) << "\t";

        //récupération couleurs :
        std::cout << std::endl << "\tcolor: " << std::endl << "\t\t";
        for (int k = 0; k < 3; k++)
            std::cout << color_keys[k] << " = " << static_cast<int>((*setting)[i]["color"][k]) << "\t";
        std::cout << std::endl;
    }
}