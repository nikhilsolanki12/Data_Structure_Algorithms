using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Data.SqlClient;
using CrystalDecisions.CrystalReports.Engine;
using CrystalDecisions.Shared; 

namespace WindowsFormsApplication1
{
    public partial class Form3 : Form
    {
              SqlConnection con = new SqlConnection(@"Data Source =LAPTOP-FBIN8P5Q;initial catalog =shop; Integrated Security=true;");
              SqlCommand cmd = new SqlCommand();
        ReportDocument rdoc = new ReportDocument();
        SqlDataAdapter sda = new SqlDataAdapter();
        String str;

    
        public Form3()
        {
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            str = "select price from product where Product_name ='" + textBox1.Text + "'";
            con.Open();
            cmd.Connection = con;
            cmd.CommandText = str;
            int price = (int)cmd.ExecuteScalar();

            ////qua = Convert.ToInt32(textBox3.Text);
          // pr = Convert.ToInt32(textBox4.Text);
           // int total = qua * pr;




            int total = price* int.Parse(textBox3.Text);
            label4.Text = total.ToString();
            label4.Visible = true;
            textBox2.Text = price.ToString();
            con.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string str2;
            string id = "select MAX(order_id) from orders";
            str2 = "insert into orders values('" + textBox1.Text + "', '" + textBox2.Text + "','" + textBox3.Text + "','" + label4.Text + "')";

            con.Open();
            cmd.Connection = con;
            cmd.CommandText = str2;
            cmd.ExecuteNonQuery();
            con.Close();
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            label4.Text = "";

        }

        private void button3_Click(object sender, EventArgs e)
        {
            DataSet1 ds1 = new DataSet1();
            string reportFilePath = @"C:\Users\ASUS\OneDrive\Documents\Visual Studio 2008\Projects\WindowsFormsApplication1\WindowsFormsApplication1\CrystalReport1.rpt";
            rdoc.Load(reportFilePath);
            string str3;
            str3 = "select * from orders where order_id =" + textBox4.Text;
            con.Open();
            cmd.Connection = con;
            cmd.CommandText = str3;
            sda.SelectCommand = cmd;
            sda.Fill(ds1, "DataTable1");
            rdoc.SetDataSource(ds1);
            crystalReportViewer1.ReportSource = rdoc;
            con.Close();
            rdoc.PrintToPrinter(1, false, 1, 1);
        }

    }
}
