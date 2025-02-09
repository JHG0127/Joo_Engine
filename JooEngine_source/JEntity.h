#pragma once
#include "Commoninclude.h"

namespace joo
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }


	private:
		std::wstring mName;

	};
}


