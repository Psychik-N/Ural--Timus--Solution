using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;
using System.Data;
using System.IO;
using System.Net;
namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            VoteOnce(Console.In.ReadToEnd());
        }
        public static Boolean VoteOnce(string s)
        {
            HttpWebRequest hwrq = (HttpWebRequest)WebRequest.Create("http://16huodong.com/index.php/haha/saveFeedBack");
            hwrq.Accept = "*/*";
            hwrq.Referer = "http://16huodong.com/index.php/haha/saveFeedBack";
            hwrq.ContentType = "application/x-www-form-urlencoded";
            hwrq.UserAgent = "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727; MAXTHON 2.0)";
            hwrq.KeepAlive = true;
            hwrq.Method = "POST";
            string PostStr = "prob=1394&data="+s;
            ASCIIEncoding ASC2E = new ASCIIEncoding();
            byte[] bytePost = ASC2E.GetBytes(PostStr);
            hwrq.ContentLength = bytePost.Length;
            Stream MyStream = hwrq.GetRequestStream();
            MyStream.Write(bytePost, 0, bytePost.Length);
            MyStream.Close();
            return true;
        }
    }
}