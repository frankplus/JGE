#include "../include/JTextInput.h"

using namespace std;

JGE* JTextInput::mEngine = NULL;

JTextInput::JTextInput()
{
    mEngine = JGE::GetInstance();
    mIsActive = false;
    mString = "";
}

JTextInput::~JTextInput()
{
}

void JTextInput::Enable()
{
    mIsActive = true;
    mString = "";
}

void JTextInput::Disable()
{
    mIsActive = false;
}

void JTextInput::Update(float dt)
{
    string input = mEngine->GetTextInput();
    mString += input;
}

void JTextInput::Render(float x, float y)
{

}