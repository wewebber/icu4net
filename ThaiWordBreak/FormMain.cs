namespace ThaiWordBreak
{
	using System;
	using System.Linq;
	using System.Windows.Forms;
	using ICU4NET;
	using ICU4NETExtension;

	public partial class FormMain : Form
	{
		public FormMain()
		{
			this.InitializeComponent();
		}

		private void UxBreakClick(object sender, EventArgs e)
		{
			using (BreakIterator bi = BreakIterator.CreateWordInstance(Locale.GetUS()))
			{
				bi.SetText(this.uxText.Text);

				var words = bi.Enumerate().ToList();

				MessageBox.Show(string.Join("-", words.ToArray()));
			}
		}

		private void UxDistinctClick(object sender, EventArgs e)
		{
			using (BreakIterator bi = BreakIterator.CreateWordInstance(Locale.GetUS()))
			{
				bi.SetText(this.uxText.Text);

				var words = bi.Enumerate()
					.Distinct()
					.OrderBy(w => w)
					.ToArray();

				MessageBox.Show(string.Join(", ", words));
			}
		}

		private void UxOccurrenceCountClick(object sender, EventArgs e)
		{
			using (BreakIterator bi = BreakIterator.CreateWordInstance(Locale.GetUS()))
			{
				bi.SetText(this.uxText.Text);

				var words = bi.Enumerate()
					.GroupBy(w => w)
					.OrderBy(x => x.Count())
					.Reverse()
					.Select(x => x.Key + " : " + x.Count())
					.Take(10)
					.ToArray();

				MessageBox.Show(string.Join(Environment.NewLine, words));
			}
		}
	}
}