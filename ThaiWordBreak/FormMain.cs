using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ICU4NET;
using ICU4NETExtension;

namespace ThaiWordBreak
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void uxBreak_Click(object sender, EventArgs e)
        {
            using (BreakIterator bi = BreakIterator.CreateWordInstance(Locale.GetUS()))
            {
                bi.SetText(uxText.Text);
                var words = bi.Enumerate().ToList(); // requires ICU4NETExtension
                uxText.Text = string.Join("-", words.ToArray());
            }
        }

        /// <summary>
        /// Using BreakIterator, the traditional way
        /// </summary>
        /// <param name="text">Text to be break</param>
        /// <returns>List of words</returns>
        private List<string> WordBreak(string text)
        {
            StringBuilder sb = new StringBuilder();
            List<string> col = new List<string>();

            using (BreakIterator bi = BreakIterator.CreateWordInstance(Locale.GetUS()))
            {
                bi.SetText(text);
                int pos = bi.First(), prev = -1;
                while (pos != BreakIterator.DONE)
                {
                    if (prev != -1)
                        col.Add(text.Substring(prev, pos - prev));
                    prev = pos;
                    pos = bi.Next();
                }
            }

            return col;
        }
    }
}
