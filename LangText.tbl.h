﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
// FILE: LangText.xlsm SHEET: 中文 KEY: id

#pragma once
#pragma pack(1)
struct LangText
{
	DWORD getUniqueID() const { return usage_id_hash(id); }

	DWORD id; // 文字ID
	char key[64]; // 名称
	char strText[1024]; // 中文
};
#pragma pack()

#if false
namespace table
{
	// LangText
	struct zLangTextEntry : public zEntry
	{
		DWORD id; // 文字ID
		char key[64]; // 名称
		char strText[1024]; // 中文

		virtual const char* getClassName() const { return "LangText"; }
		static const char* getFileName() { return "LangText.tbl"; }
		void fill(const LangText& base)
		{
			this->id = base.getUniqueID();

			this->id = base.id;
			strncpy(this->key, base.key, 64);
			strncpy(this->strText, base.strText, 1024);
		}
		void reset()
		{
			this->id = 0;
			this->key[0] = '\0';
			this->strText[0] = '\0';
		}
	};
	typedef zDataBM<zLangTextEntry, LangText> LangTextManager;
}
#endif
