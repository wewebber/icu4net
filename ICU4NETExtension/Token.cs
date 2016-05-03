using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ICU4NETExtension
{
    using System.Collections.Generic;

    public class Token
    {
        public int Start { get; private set; }

        public int End { get; private set; }

        public string Text { get; private set; }

        /// <summary>
        /// Gets the (breaker-specific) rule status associated with the token.
        /// </summary>
        /// <remarks>Of standard <c>ICU</c> break iterators, only word
        /// and sentence breakers return codes (specifically, rule statuses).
        /// These are defined in <c>ubrk.h</c> of the <c>ICU</c> source code.
        /// The most salient feature is that for the word breaker, code <c>0</c>
        /// indicates a non-word.</remarks>
        public int RuleStatus { get; private set; }

        public Token(int start, int end, string text, int ruleStatus)
        {
            this.Start = start;
            this.End = end;
            this.Text = text;
            this.RuleStatus = ruleStatus;
        }
    }
}
