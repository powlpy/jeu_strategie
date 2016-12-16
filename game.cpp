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
#include <gf/Shape.h>


Game::Game()
: graphicsManager(objectsManager)
{
  //players[0] = Player();
  objectsManager.addArchetype("bombe", "medievalUnit_01.png", {50, 50});
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 250)));
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(350, 250)));
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 350)));
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
                  if(event.key.keycode != gf::Keycode::Backspace){
                    objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], obj.getPosition() + Vector2d(0, 30)));
                  }
                  else{
                    obj.kill();
                    idxObject = -1;
                  }
                }
              }
            break;
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

    renderer.clear(gf::Color::rgba(39.0f,174.0f,96.0f,255.0f));
    // Draw the entities
    objectsManager.render(renderer);

    renderer.draw(ui1);
    renderer.draw(ui2);
    renderer.draw(ui3);
    
    gf::RectangleShape rect({10, 10});
    rect.setColor(gf::Color::Red);
    rect.setPosition(mousePosition);
    rect.setAnchor(gf::Anchor::Center);
    renderer.draw(rect);

    renderer.display();
  }
} 
