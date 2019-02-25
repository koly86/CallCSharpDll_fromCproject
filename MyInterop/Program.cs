using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace MyInterop
{
    [Guid("8E78371F-DEDF-4ABA-8229-5D2AB44E8C31")]
    public interface IMyDotNetInterface
    {
        void ShowCOMDialog();
        string ComeToMe(string str);
    }

    [ClassInterface(ClassInterfaceType.None)]
    [Guid("1B51E581-63CC-433E-B212-AC017C41197A")]
    public class MyDotNetClass : IMyDotNetInterface
    {
        // Need a public default constructor for COM Interop.
        public MyDotNetClass()
        { }
        public void ShowCOMDialog()
        {
            System.Windows.Forms.MessageBox.Show("I am a Managed DotNET C# COM Object Dialog");
        }

        public string ComeToMe(string str)
        {
            System.Windows.Forms.MessageBox.Show(str);
            switch (str)
            {
               case "Hi": return "Hi world";
                break;
            }

            return "Nothing to Show";
        }
    }
}