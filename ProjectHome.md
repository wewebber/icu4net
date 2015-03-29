**ICU4NET** provides binding for .NET language over ICU4C.

Currently, we focus on implementing only the boundary analysis part.

## Boundary Analysis / Word Breaking ##
This example shows how to perform word breaking on a given string and get the result in enumerable form. Enumerate is implemented as C# Extension Method of `BreakIterator`, and requires `ICU4NETExtension` to be imported.

```
// using ICU4NET;
// using ICU4NETExtension;

using (BreakIterator bi = BreakIterator.CreateWordInstance(Locale.GetUS()))
{
    bi.SetText(uxText.Text);

    // requires ICU4NETExtension to use Enumerate extension method
    var words = bi.Enumerate().ToList(); 
    uxText.Text = string.Join("-", words.ToArray());
}
```

By providing this `IEnumerable` interface, `ICU4NETExtension` allows you to do something like this:

```
using (BreakIterator bi = BreakIterator.CreateWordInstance(Locale.GetUS()))
{
    bi.SetText(uxText.Text);

    // requires ICU4NETExtension to use Enumerate extension method
    MessageBox.Show(string.Join(Environment.NewLine, bi.Enumerate()
        .GroupBy(w => w)
        .OrderBy(x => x.Count())
        .Reverse()
        .Select(x => x.Key + " : " + x.Count())
        .Take(10)
        .ToArray()));
}
```

This another example shows code which produces the same result, using the traditional way as used in original ICU4C/ICU4J and their documentation

```
// using ICU4NET;

private List<string> WordBreak(string text)
{
    var sb = new StringBuilder();
    var col = new List<string>();

    using (BreakIterator bi = BreakIterator.CreateWordInstance(Locale.GetUS()))
    {
        bi.SetText(text);
        int start = bi.First(), end = bi.Next();
        while (end != BreakIterator.DONE)
        {
            col.Add(text.Substring(start, end - start));
            start = end; end = bi.Next();
        }
    }

    return col;
}
```

## How to use ##
  1. Add references to ICU4NET.dll and ICU4NETExtension.dll.
  1. Make sure that ICU4C's DLLs, including icudt42.dll, icuin42.dll, icuio42.dll, icule42.dll, iculx42.dll, icutu41.dll, and icuuc42.dll, are in the %PATH% or in the working directory of your exe program.

## Example Application ##
Features:
  * Break input text into words
  * List distinct words in text, sorted alphabetically
  * List top ten words with most occurrence.

![http://lh5.ggpht.com/_5XDoB4MglkY/S4_6QN_lq3I/AAAAAAAAFk0/LsUGhSGloIw/s800/WordBreak.png](http://lh5.ggpht.com/_5XDoB4MglkY/S4_6QN_lq3I/AAAAAAAAFk0/LsUGhSGloIw/s800/WordBreak.png)