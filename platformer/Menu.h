#include "Scene.h"

class Menu : public Scene {
public:
	// ————— STATIC ATTRIBUTES ————— //
    // ————— DESTRUCTOR ————— //
    ~Menu();

    // ————— METHODS ————— //
    void initialise() override;
    void update(float delta_time) override;
    void render(ShaderProgram* program) override;
};

