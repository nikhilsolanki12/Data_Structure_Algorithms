using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.IO;


namespace WindowsFormsApplication1
{
    public partial class Form2 : Form
    {
        SqlConnection con = new SqlConnection(@"Data Source =LAPTOP-FBIN8P5Q;initial catalog =shop; Integrated Security=true;");
        SqlCommand cmd = new SqlCommand();
        BarcodeLib.Barcode b = new BarcodeLib.Barcode();
        string barcodeimage, dt = "";
        String path = Application.StartupPath + "/Barcode/";
        string str;
        public Form2()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            byte[] mydata;
            FileInfo finfo = new FileInfo(path + barcodeimage);
            long numbyte = finfo.Length;
            FileStream fstream = new FileStream(path + barcodeimage, FileMode.Open, FileAccess.Read);
            BinaryReader breader = new BinaryReader(fstream);
            mydata = breader.ReadBytes(Convert.ToInt32(numbyte));

            str = "insert into product values('" + textBox1.Text + "', '" + textBox2.Text + "', '" + textBox3.Text + "',@img)";
            con.Open();
            cmd.Connection = con;
            cmd.Parameters.Add(new SqlParameter("@img", (object)mydata));
            cmd.CommandText = str;
            cmd.ExecuteNonQuery();
            con.Close();
            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            textBox1.Focus();
            label4.Visible = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            dt = textBox1.Text.ToUpper();
            barcodeimage = dt + ".png";
            createbarcode();

        }
        public void createbarcode()
        {
            Bitmap temp = new Bitmap(1, 1);
            temp.SetPixel(0, 0, this.BackColor);
            pictureBox1.Image = (Image)temp;

            int W = Convert.ToInt32(200);
            int H = Convert.ToInt32(50);

            BarcodeLib.TYPE type = BarcodeLib.TYPE.UNSPECIFIED;
            type = BarcodeLib.TYPE.CODE39;

            if (type != BarcodeLib.TYPE.UNSPECIFIED)
            {
                b.IncludeLabel = true;
                pictureBox1.Image = b.Encode(type, dt.Trim(), this.ForeColor, this.b.BackColor, W, H);
            }

            pictureBox1.Height = pictureBox1.Image.Height;
            pictureBox1.Width = pictureBox1.Image.Width;
            pictureBox1.Image.Save(path + barcodeimage);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            textBox1.Focus();
        }

    }
}
