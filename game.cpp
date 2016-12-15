#include "game.h"
#include "vector2d.h"
// C'est un test tout ne devrait pas etre dans le run
#include <gf/Event.h>
#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <gf/Shapes.h>
#include <gf/Clock.h>


Game::Game()
: graphicsManager(objectsManager)
{
  //players[0] = Player();
  objectsManager.addArchetype("bombe", "sprite.png", {200, 200});
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 250)));
}

void Game::run(){

  gf::RenderWindow& renderer = graphicsManager.getRenderer();
  gf::Window& window = graphicsManager.getWindow();

  PhysicObject* obj = nullptr;
  // Start the game loop

  gf::Clock clock;
  while (window.isOpen()) {
    // Process events
    gf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case gf::EventType::Closed:
          window.close();
          break;
        case gf::EventType::MouseButtonPressed:
          if(event.mouseButton.button == gf::MouseButton::Left){
            obj = objectsManager.getObjectByPosition(Vector2d(event.mouseButton.coords.x, event.mouseButton.coords.y));
          }
          else if(event.mouseButton.button == gf::MouseButton::Right){
            if(obj != nullptr){
              obj->setGoal(Vector2d(event.mouseButton.coords.x, event.mouseButton.coords.y));
              std::cout << obj << std::endl;
            }
          }
        default:
          break;
      }
    }


    float dt = clock.restart().asSeconds();
    objectsManager.update(dt);

    renderer.clear(gf::Color::White);
    // Draw the entities
    objectsManager.render(renderer);

    renderer.display();
  }
}