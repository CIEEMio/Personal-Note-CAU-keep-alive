package MyAccessConnection;


import java.sql.*;
import javax.swing.*;

public class MyBusiness { //ʵ�ִ����ݿ⣬����ɾ���ġ��鹦��
    private Connection con = null;
    private Statement access = null;
    public void connection(String database)
    {
	try {
		// ����JDBC-ODBC����������
            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
            this.con = DriverManager.getConnection("jdbc:odbc:"+database);
            this.access = con.createStatement( );
	} catch (ClassNotFoundException | SQLException e) {
            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());       
	}
    }
//    //������
//    public void Createtable(String s)
//    {
//        String sql = "create tabale "+s;
//        try {
//            access.executeUpdate(sql); } 
//        catch (SQLException e) {
//            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
//        }
//    }
//    //ɾ����
//    public void Deletetable(String s)
//    {
//        String sql = "drop table "+s;
//        try {
//            this.access.executeUpdate(sql); } 
//        catch (SQLException e) {
//            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
//        }
//    
//    }
//    //�޸ı���
//    public void Altertable(String name, String rename)
//    {
//        String sql ="alter table "+ name +" rename to "+rename;
//        try {
//            access.execute(sql);
//        } catch (SQLException e) {
//            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
//        } 
//    }
    //�����¼
    public void Add(String table, String value)
    {
        String sql = "insert into "+ table + " values(" + value + ")" ;
        try {
            access.execute(sql);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
        } 
    }
    //ɾ����¼
    public void Delete(String table, String value)
    {
        String sql = "delete from "+ table + " where ѧ�� =" + value;
        try {
            access.execute(sql);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
        } 
    }

//    public static ResultSet GetName()
//    {
//        String sql = "SELECT * FROM $tableName limit 0";
//        try {
//            ResultSet rs = access.executeQuery(sql);
//            return rs;
//        } catch (SQLException e) {
//            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
//        }   
//        return null;
//    }
    //�޸ļ�¼    
    public void Update(String table, String value)
    {
        String sql = "update "+ table + "set "+value;
        try {
            this.access.execute(sql);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
        }         
    }
    //��ѯ��¼����ѡ���У�
    public ResultSet Query1(String table , String condition )
    {
        String sql ="select * from "+table+" where "+condition;
        //+ table + " where "+condition;
        try {
            ResultSet rs =access.executeQuery(sql);
            return rs;
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
        }
        return null;
    }
        //��ѯ��¼����������
    public ResultSet Query2(String s)
    {
        String sql ="select * from "+s;
        try {
            ResultSet rs =access.executeQuery(sql);
            return rs;
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
        }
        return null;
    }
    //�ر����ݿ⼰����
    public void Shutdownaccess()
    {
        try {
            con.close();
            access.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null,"��������:"+e.getMessage());
        }
    }
    

}
