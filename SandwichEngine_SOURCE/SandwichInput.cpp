#include "SandwichInput.h"

namespace Sandwich
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[static_cast<UINT>(eKeyCode::End)] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initialize()
	{
		//mKeys.resize(static_cast<UINT>(eKeyCode::End));

		for (size_t i = 0; i < static_cast<UINT>(eKeyCode::End); ++i)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = static_cast<eKeyCode>(i);

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); ++i)
		{
			// 키가 눌렸는지 아닌지
			if (GetAsyncKeyState(ASCII[i]) & 0x08000)
			{
				// 이전 프레임에도 눌려있었다면 Pressed, 아니면 Down
				mKeys[i].state = mKeys[i].bPressed ? eKeyState::Pressed : eKeyState::Down;
				mKeys[i].bPressed = true;
			}
			else
			{
				// 이전 프레임에 눌려있었다면 Up, 아니면 None,
				mKeys[i].state = mKeys[i].bPressed ? eKeyState::Up : eKeyState::None;
				mKeys[i].bPressed = false;
			}
		}
	}
}
