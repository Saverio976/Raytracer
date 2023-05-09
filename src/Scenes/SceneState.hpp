/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** SceneState.hpp
*/

#ifndef SCENESTATE_HPP_
    #define SCENESTATE_HPP_

    #include <mutex>
    #include "ISceneState.hpp"

namespace RayTracer::Scenes {
    /**
     * @brief The SceneState class
     *
     * class that represent a scene state (to know if the scene is running or not)
     * (or if the scene render need to be cancelled)
     */
    class SceneState : public ISceneState {
        public:
            /**
             * @brief SceneState
             */
            SceneState();
            /**
             * @brief Get the state (thread safe)
             *
             * @return the state
             */
            ISceneState::States getState() const final;
            /**
             * @brief Change the state (thread safe)
             *
             * @param state the state
             */
            void changeState(const ISceneState::States &state) final;
        private:
            States _state;
            std::mutex mutex;
    };
}

#endif
