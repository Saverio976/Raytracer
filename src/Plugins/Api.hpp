/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Api.hpp
*/

#ifndef API_HPP_
    #define API_HPP_

    #include <vector>

extern "C" {
    /**
     * @brief Get the creator
     *
     * The creator must be a class that has a `.create(const ISetting &settings)` method.
     * This method must create an [ ILight | ICamera | IPrimitive | IFilter ].
     * There is no verification that the returning value is ok.
     * So be cautious. Thx.
     * For [ ILight | ICamera | IPrimitive ] they must inherite from IEntityCreator.
     * For [ IFilter ] they must inherite from IFilterCreator.
     *
     * @return the creator
     */
    void *getCreator(void);
    /**
     * @brief Delete the creator (created with the `getCreator()` method)
     *
     * @param creator
     */
    void deleteCreator(void *creator);
}

#endif
