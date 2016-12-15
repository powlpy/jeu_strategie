#include "game.h"
#include "vector2d.h"
// C'est un test tout ne devrait pas etre dans le run
#include <gf/Event.h>
#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <gf/Shapes.h>
#include <gf/Clock.h>
#include <gf/UI.h>
#include <gf/Font.h>


Game::Game()
: graphicsManager(objectsManager)
{
  //players[0] = Player();
  objectsManager.addArchetype("bombe", "sprite.png", {200, 200});
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 250)));
}

void Game::run(){
  gf::Font font;
  gf::RenderWindow& renderer = graphicsManager.getRenderer();
  gf::Window& window = graphicsManager.getWindow();
  gf::DefaultUIRenderer uiRenderer(font);
  gf::UILayout  layout;
  gf::UI ui1(uiRenderer, layout);
  gf::UI ui2(uiRenderer, layout);
  gf::UI ui3(uiRenderer, layout);
  float scrollArea = 0;

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
      ui1.update(event);
      ui2.update(event);
      ui3.update(event);
    }
    ui1.clear();
    ui1.beginScrollArea("Scroll area", {10.0f, 490.0f, 200.0f, 200.0f}, &scrollArea);
    ui1.endScrollArea();

    ui2.clear();
    ui2.beginScrollArea("Scroll area", {220.0f, 540.0f, 700.0f, 150.0f}, &scrollArea);
    ui1.separatorLine();
    ui1.separator();
    ui2.endScrollArea();

    ui3.clear();
    ui3.beginScrollArea("Scroll area", {930.0f, 490.0f, 360.0f, 200.0f}, &scrollArea);
    ui3.button("Button1");
    ui3.button("Button2");
    ui3.button("Button3");
    ui3.endScrollArea();

    float dt = clock.restart().asSeconds();
    objectsManager.update(dt);

    renderer.clear(gf::Color::White);
    // Draw the entities
    objectsManager.render(renderer);
    renderer.draw(ui1);
    renderer.draw(ui2);
    renderer.draw(ui3);
    renderer.display();
  }
} 