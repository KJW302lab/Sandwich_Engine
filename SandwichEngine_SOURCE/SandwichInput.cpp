#include "SandwichInput.h"

namespace Sandwich
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[static_cast<UINT>(eKeyCode::End)] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		MK_LBUTTON, MK_RBUTTON,
		VK_SPACE,
	};

	void Input::Initialize()
	{
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < static_cast<UINT>(eKeyCode::End); ++i)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = static_cast<eKeyCode>(i);

			Keys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		for (Key& key : Keys)
			updateKey(key);
	}

	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keyCode))
			updateKeyDown(key);
		else
			updateKeyUp(key);
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[static_cast<UINT>(code)]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		key.state = key.bPressed ? eKeyState::Pressed : eKeyState::Down;
		key.bPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		key.state = key.bPressed ? eKeyState::Up : eKeyState::None;
		key.bPressed = false;
	}
}
