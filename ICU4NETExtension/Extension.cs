using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ICU4NET;

namespace ICU4NETExtension
{
    public static class Extension
    {
        public static IEnumerable<string> Enumerate(this BreakIterator bi)
        {
            StringBuilder sb = new StringBuilder();
            String text = bi.GetCLRText();
               int pos = bi.First(), prev = -1;
                while (pos != BreakIterator.DONE)
                {
                    if (prev != -1)
                        yield return text.Substring(prev, pos - prev);
                    prev = pos;
                    pos = bi.Next();
                }
            }
            
        }
    }

