/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ISceneState.hpp
*/

#ifndef ISCENESTATE_HPP_
    #define ISCENESTATE_HPP_

namespace RayTracer::Scenes {
    /**
     * @brief The SceneState interface
     *
     * class that represent a scene state (to know if the scene is running or not)
     * (or if the scene render need to be cancelled)
     */
    class ISceneState {
        public:
            /**
             * @brief The States
             */
            enum class States {
                RUNNING,
                CANCELLED,
                FINISHED
            };
            /**
             * @brief Get the state (thread safe)
             *
             * @return the state
             */
            virtual States getState() const = 0;
            /**
             * @brief Change the state (thread safe)
             *
             * @param state the state
             */
            virtual void changeState(const States &state) = 0;
    };
}

#endif
