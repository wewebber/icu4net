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
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.uxDistinct = new System.Windows.Forms.Button();
            this.uxOccurrenceCount = new System.Windows.Forms.Button();
            this.uxPanelContainer = new System.Windows.Forms.Panel();
            this.flowLayoutPanel1.SuspendLayout();
            this.uxPanelContainer.SuspendLayout();
            this.SuspendLayout();
            // 
            // uxBreak
            // 
            this.uxBreak.Location = new System.Drawing.Point(3, 3);
            this.uxBreak.Name = "uxBreak";
            this.uxBreak.Size = new System.Drawing.Size(135, 27);
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
            this.uxText.Size = new System.Drawing.Size(702, 326);
            this.uxText.TabIndex = 1;
            this.uxText.Text = resources.GetString("uxText.Text");
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.AutoSize = true;
            this.flowLayoutPanel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.flowLayoutPanel1.Controls.Add(this.uxBreak);
            this.flowLayoutPanel1.Controls.Add(this.uxDistinct);
            this.flowLayoutPanel1.Controls.Add(this.uxOccurrenceCount);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(0, 326);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(702, 33);
            this.flowLayoutPanel1.TabIndex = 2;
            // 
            // uxDistinct
            // 
            this.uxDistinct.Location = new System.Drawing.Point(144, 3);
            this.uxDistinct.Name = "uxDistinct";
            this.uxDistinct.Size = new System.Drawing.Size(135, 27);
            this.uxDistinct.TabIndex = 1;
            this.uxDistinct.Text = "Distinct Words";
            this.uxDistinct.UseVisualStyleBackColor = true;
            this.uxDistinct.Click += new System.EventHandler(this.uxDistinct_Click);
            // 
            // uxOccurrenceCount
            // 
            this.uxOccurrenceCount.Location = new System.Drawing.Point(285, 3);
            this.uxOccurrenceCount.Name = "uxOccurrenceCount";
            this.uxOccurrenceCount.Size = new System.Drawing.Size(135, 27);
            this.uxOccurrenceCount.TabIndex = 2;
            this.uxOccurrenceCount.Text = "Occurrence Count";
            this.uxOccurrenceCount.UseVisualStyleBackColor = true;
            this.uxOccurrenceCount.Click += new System.EventHandler(this.uxOccurrenceCount_Click);
            // 
            // uxPanelContainer
            // 
            this.uxPanelContainer.Controls.Add(this.uxText);
            this.uxPanelContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.uxPanelContainer.Location = new System.Drawing.Point(0, 0);
            this.uxPanelContainer.Name = "uxPanelContainer";
            this.uxPanelContainer.Size = new System.Drawing.Size(702, 326);
            this.uxPanelContainer.TabIndex = 3;
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(702, 359);
            this.Controls.Add(this.uxPanelContainer);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Name = "FormMain";
            this.Text = "Thai Word Break";
            this.flowLayoutPanel1.ResumeLayout(false);
            this.uxPanelContainer.ResumeLayout(false);
            this.uxPanelContainer.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button uxBreak;
        private System.Windows.Forms.TextBox uxText;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Button uxDistinct;
        private System.Windows.Forms.Button uxOccurrenceCount;
        private System.Windows.Forms.Panel uxPanelContainer;
    }
}

