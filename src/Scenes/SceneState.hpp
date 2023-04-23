/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneState.hpp
*/

#ifndef SCENESTATE_HPP_
    #define SCENESTATE_HPP_

    #include <mutex>

namespace RayTracer::Scenes {
    /**
     * @brief The SceneState class
     *
     * class that represent a scene state (to know if the scene is running or not)
     * (or if the scene render need to be cancelled)
     */
    class SceneState {
        public:
            /**
             * @brief The States
             */
            enum class States {
                RUNNING,
                CANCELLED
            };
            /**
             * @brief Get the state (thread safe)
             *
             * @return the state
             */
            States getState() const;
            /**
             * @brief Change the state (thread safe)
             *
             * @param state the state
             */
            void changeState(const States &state);
        private:
            States _state;
            std::mutex mutex;
    };
}

#endif
