#include <iostream>
#include <libconfig.h++>
#include "ConfigWrapper.hpp"
#include "ISetting.hpp"

/*
 * Exemple d'un code récupérant les informations concernant les sphères dans le fichier testScene.yaax
 */
int main(int ac, char **av) {
    RayTracer::Scenes::ConfigWrapper test;
    char keys[5] = "xyzr";
    char color_keys[4] = "rgb";

    test.readFile("./testScene.yaax");

    const std::shared_ptr<RayTracer::Scenes::ISetting> setting = test.getSetting();

    //récupération de l'objet contenant les sphères
    setting->getSetting("primitives.spheres");
    //parsing des deux sphères
    for (int i = 0; i < setting->getLength(); i++) {
        //récupération coordonnées :
        std::cout << "sphere[" << i << "]" << std::endl << "\tcoords: " << std::endl << "\t\t";
        for (int j = 0; j < 4; j++)
            std::cout << keys[j] << " = " << static_cast<int>(*(setting->get(i)->get(j))) << "\t";

        //récupération couleurs :
        std::cout << std::endl << "\tcolor: " << std::endl << "\t\t";
        for (int k = 0; k < 3; k++)
            std::cout << color_keys[k] << " = " << static_cast<int>(*(setting->get(i)->get("color")->get(k))) << "\t";
        std::cout << std::endl;
    }
}
