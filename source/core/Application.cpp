/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:
 *
 *        Created:  14/12/2014 05:09:21
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <cstdlib>
#include <ctime>

#include "Application.hpp"
#include "Config.hpp"
#include "Exception.hpp"
#include "GameState.hpp"
#include "Mouse.hpp"
#include "OpenGL.hpp"
#include "SDLHeaders.hpp"

void Application::init() {
	CoreApplication::init();

	createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, APP_NAME);
	m_window.setMouseCursorGrabbed(true);
	m_window.setMouseCursorVisible(false);
	m_window.setVerticalSyncEnabled(true);

	m_renderer.init(m_window);

	m_stateStack.push<GameState>();
}

// void Application::handleEvents() {
// 	Mouse::reset();
//
// 	SDL_Event event;
// 	while(SDL_PollEvent(&event) != 0) {
// 		switch(event.type) {
// 			case SDL_QUIT:
// 				m_window.close();
// 				break;
// 			case SDL_KEYDOWN:
// 				if(event.key.keysym.sym == SDLK_ESCAPE) {
// 					m_window.close();
// 				}
// 				break;
// 			case SDL_MOUSEMOTION:
// 				// Mouse::update(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel);
// 				if(SCREEN_WIDTH / 2 != event.motion.x || SCREEN_HEIGHT / 2 != event.motion.y) {
// 					Camera::getInstance().turnH(event.motion.xrel * 0.06);
// 					Camera::getInstance().turnV(-event.motion.yrel * 0.06);
//
// 					SDL_WarpMouseInWindow(m_window.window(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
// 				}
// 				break;
// 			default:
// 				break;
// 		}
// 	}
// }

