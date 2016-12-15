#include "game.h"
#include "vector2d.h"
// C'est un test tout ne devrait pas etre dans le run
#include <gf/Event.h>
#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <gf/Shapes.h>


Game::Game()
: graphicsManager(objectsManager)
{
  //players[0] = Player();
  objectsManager.addArchetype("bombe", "sprite.png");
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 250)));
}

void Game::run(){

  gf::RenderWindow& renderer = graphicsManager.getRenderer();
  gf::Window& window = graphicsManager.getWindow();
  // Start the game loop
  while (window.isOpen()) {
    // Process events
    gf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case gf::EventType::Closed:
          window.close();
          break;
        default:
          break;
      }
    }

    renderer.clear(gf::Color::White);
    // Draw the entities
    objectsManager.render(renderer);

    renderer.display();
  }
}