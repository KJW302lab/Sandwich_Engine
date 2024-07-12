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
			// Ű�� ���ȴ��� �ƴ���
			if (GetAsyncKeyState(ASCII[i]) & 0x08000)
			{
				// ���� �����ӿ��� �����־��ٸ� Pressed, �ƴϸ� Down
				mKeys[i].state = mKeys[i].bPressed ? eKeyState::Pressed : eKeyState::Down;
				mKeys[i].bPressed = true;
			}
			else
			{
				// ���� �����ӿ� �����־��ٸ� Up, �ƴϸ� None,
				mKeys[i].state = mKeys[i].bPressed ? eKeyState::Up : eKeyState::None;
				mKeys[i].bPressed = false;
			}
		}
	}
}
