package MyAccessConnection;


import java.sql.*;
import javax.swing.*;

public class MyBusiness { //实现打开数据库，增、删、改、查功能
    private Connection con = null;
    private Statement access = null;
    public void connection(String database)
    {
	try {
		// 加载JDBC-ODBC桥驱动程序
            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
            this.con = DriverManager.getConnection("jdbc:odbc:"+database);
            this.access = con.createStatement( );
	} catch (ClassNotFoundException | SQLException e) {
            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());       
	}
    }
//    //建立表
//    public void Createtable(String s)
//    {
//        String sql = "create tabale "+s;
//        try {
//            access.executeUpdate(sql); } 
//        catch (SQLException e) {
//            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
//        }
//    }
//    //删除表
//    public void Deletetable(String s)
//    {
//        String sql = "drop table "+s;
//        try {
//            this.access.executeUpdate(sql); } 
//        catch (SQLException e) {
//            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
//        }
//    
//    }
//    //修改表名
//    public void Altertable(String name, String rename)
//    {
//        String sql ="alter table "+ name +" rename to "+rename;
//        try {
//            access.execute(sql);
//        } catch (SQLException e) {
//            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
//        } 
//    }
    //插入记录
    public void Add(String table, String value)
    {
        String sql = "insert into "+ table + " values(" + value + ")" ;
        try {
            access.execute(sql);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
        } 
    }
    //删除记录
    public void Delete(String table, String value)
    {
        String sql = "delete from "+ table + " where 学号 =" + value;
        try {
            access.execute(sql);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
        } 
    }

//    public static ResultSet GetName()
//    {
//        String sql = "SELECT * FROM $tableName limit 0";
//        try {
//            ResultSet rs = access.executeQuery(sql);
//            return rs;
//        } catch (SQLException e) {
//            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
//        }   
//        return null;
//    }
    //修改记录    
    public void Update(String table, String value)
    {
        String sql = "update "+ table + "set "+value;
        try {
            this.access.execute(sql);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
        }         
    }
    //查询记录（无选定列）
    public ResultSet Query1(String table , String condition )
    {
        String sql ="select * from "+table+" where "+condition;
        //+ table + " where "+condition;
        try {
            ResultSet rs =access.executeQuery(sql);
            return rs;
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
        }
        return null;
    }
        //查询记录（无条件）
    public ResultSet Query2(String s)
    {
        String sql ="select * from "+s;
        try {
            ResultSet rs =access.executeQuery(sql);
            return rs;
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
        }
        return null;
    }
    //关闭数据库及连接
    public void Shutdownaccess()
    {
        try {
            con.close();
            access.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"发生错误:"+e.getMessage());
        }
    }
    

}
