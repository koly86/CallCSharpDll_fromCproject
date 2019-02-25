// DotNet_COM_Call.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#import "MyInterop.tlb" named_guids raw_interfaces_only



int main()
{
	CoInitialize(NULL);   //Initialize all COM Components
	MyInterop::IMyDotNetInterfacePtr pDotNetCOMPtr;
	HRESULT hRes =
		pDotNetCOMPtr.CreateInstance(MyInterop::CLSID_MyDotNetClass);
	if (hRes == S_OK)
	{
		BSTR str;
		BSTR* retVal = NULL;
		_bstr_t bstr1("This is the test string.");

		BSTR bstr;

		bstr = bstr1.copy();
		pDotNetCOMPtr->ShowCOMDialog();
		pDotNetCOMPtr->ComeToMe(bstr, retVal);
		printf("%s\n", retVal); //not working
		//call .NET COM exported function ShowDialog ()
	}
	CoUninitialize();
	return 0;
}


