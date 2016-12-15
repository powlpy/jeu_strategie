#include "game.h"
#include "vector2d.h"
// C'est un test tout ne devrait pas etre dans le run
#include <gf/Event.h>
#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <gf/Shapes.h>
#include <gf/Clock.h>
#include <gf/Shape.h>


Game::Game()
: graphicsManager(objectsManager)
{
  //players[0] = Player();
  objectsManager.addArchetype("bombe", "sprite.png", {200, 200});
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 250)));
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(350, 250)));
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 350)));
}

void Game::run(){

  gf::RenderWindow& renderer = graphicsManager.getRenderer();
  gf::Window& window = graphicsManager.getWindow();

  int idxObject = -1;
  gf::Vector2f mousePosition = {0, 0};
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
            idxObject = objectsManager.getIdxObjectByPosition(Vector2d(event.mouseButton.coords.x, event.mouseButton.coords.y));
          }
          else if(event.mouseButton.button == gf::MouseButton::Right){
            if(idxObject >= 0){
              objectsManager.getObject(idxObject).setGoal(Vector2d(event.mouseButton.coords.x, event.mouseButton.coords.y));
            }
          }
        break;
          case gf::EventType::MouseMoved:
            mousePosition = event.mouseCursor.coords;
            break;
          case gf::EventType::KeyPressed:
              if(idxObject >= 0){
                PhysicObject& obj = objectsManager.getObject(idxObject);
                if(obj.isAlive()){
                  if(event.key.keycode != gf::Keycode::Backspace)
                    objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], obj.getPosition() + Vector2d(0, 30)));
                  else
                    obj.kill();
                }
              }
            break;
        default:
          break;
      }
    }


    float dt = clock.restart().asSeconds();
    objectsManager.update(dt);

    renderer.clear(gf::Color::White);
    // Draw the entities
    objectsManager.render(renderer);
    gf::RectangleShape rect({10, 10});
    rect.setColor(gf::Color::Red);
    rect.setPosition(mousePosition);
    rect.setAnchor(gf::Anchor::Center);
    renderer.draw(rect);

    renderer.display();
  }
}