namespace ThaiWordBreak
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.uxBreak = new System.Windows.Forms.Button();
            this.uxText = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // uxBreak
            // 
            this.uxBreak.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.uxBreak.Location = new System.Drawing.Point(0, 237);
            this.uxBreak.Name = "uxBreak";
            this.uxBreak.Size = new System.Drawing.Size(502, 23);
            this.uxBreak.TabIndex = 0;
            this.uxBreak.Text = "Break!";
            this.uxBreak.UseVisualStyleBackColor = true;
            this.uxBreak.Click += new System.EventHandler(this.uxBreak_Click);
            // 
            // uxText
            // 
            this.uxText.Dock = System.Windows.Forms.DockStyle.Fill;
            this.uxText.Font = new System.Drawing.Font("Tahoma", 10.18868F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.uxText.Location = new System.Drawing.Point(0, 0);
            this.uxText.Multiline = true;
            this.uxText.Name = "uxText";
            this.uxText.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.uxText.Size = new System.Drawing.Size(502, 237);
            this.uxText.TabIndex = 1;
            this.uxText.Text = resources.GetString("uxText.Text");
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(502, 260);
            this.Controls.Add(this.uxText);
            this.Controls.Add(this.uxBreak);
            this.Name = "FormMain";
            this.Text = "Thai Word Break";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button uxBreak;
        private System.Windows.Forms.TextBox uxText;
    }
}

