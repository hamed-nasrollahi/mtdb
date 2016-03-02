
class __declspec(dllimport) MqlAdapter
{

public:
    MqlAdapter();

	void Init();

	void WriteValue(wchar_t* sqlStr);

	void Close();
};
