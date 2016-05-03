namespace ICU4NETExtension
{
	using System.Collections.Generic;
	using ICU4NET;

	public static class Extension
	{
		public static IEnumerable<string> Enumerate(this BreakIterator bi)
		{
			string text = bi.GetCLRText();
			int start = bi.First(), end = bi.Next();
			while (end != BreakIterator.DONE)
			{
				yield return text.Substring(start, end - start);
				start = end;
				end = bi.Next();
			}
		}

		public static IEnumerable<Token> EnumerateTokens(this BreakIterator bi)
		{
			string text = bi.GetCLRText();
			int start = bi.First(), end = bi.Next();
			while (end != BreakIterator.DONE)
			{
                yield return new Token(start, end, text.Substring(start, end - start), bi.GetRuleStatus());
				start = end;
				end = bi.Next();
			}
		}
	}
}