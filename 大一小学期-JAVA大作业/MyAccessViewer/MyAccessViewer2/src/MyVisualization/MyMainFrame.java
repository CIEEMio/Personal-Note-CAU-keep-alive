

package MyVisualization;

import MyAccessConnection.MyBusiness;
import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.Vector;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.TreePath;


public class MyMainFrame extends javax.swing.JFrame {
    public MyBusiness business;

    /**
     * Creates new form NewJFrame1
     */
    public MyMainFrame() {
        initComponents();
        addEvents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {
        business = new MyAccessConnection.MyBusiness();
        business.connection("AccessDatabase");
        jMenuItem1 = new javax.swing.JMenuItem();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTree1 = new javax.swing.JTree();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jMenuBar1 = new javax.swing.JMenuBar();
        MenuSystem = new javax.swing.JMenu();
        MenuExit = new javax.swing.JMenuItem();
        MenuUpdate = new javax.swing.JMenu();
        MenuDelete = new javax.swing.JMenuItem();
        MenuAdd = new javax.swing.JMenuItem();
        MenuChange = new javax.swing.JMenuItem();
        MenuQuery = new javax.swing.JMenu();
        MenuQueryall = new javax.swing.JMenuItem();
        MenuAbout = new javax.swing.JMenu();
        Aboutme = new javax.swing.JMenuItem();

        jMenuItem1.setText("查询全表");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        javax.swing.tree.DefaultMutableTreeNode treeNode1 = new javax.swing.tree.DefaultMutableTreeNode("表");
        javax.swing.tree.DefaultMutableTreeNode treeNode2 = new javax.swing.tree.DefaultMutableTreeNode("Student");
        treeNode1.add(treeNode2);
        treeNode2 = new javax.swing.tree.DefaultMutableTreeNode("Score");
        treeNode1.add(treeNode2);
        treeNode2 = new javax.swing.tree.DefaultMutableTreeNode("Prize");
        treeNode1.add(treeNode2);
        jTree1.setModel(new javax.swing.tree.DefaultTreeModel(treeNode1));
        jScrollPane1.setViewportView(jTree1);

        jTable1=null;
        jScrollPane2.setViewportView(jTable1);

        MenuSystem.setText("系统");

        MenuExit.setText("退出");
        MenuExit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                MenuExitActionPerformed(evt);
                business.Shutdownaccess();
            }
        });
        MenuSystem.add(MenuExit);

        jMenuBar1.add(MenuSystem);

        MenuUpdate.setText("更新数据");

        MenuDelete.setText("删除");
        MenuUpdate.add(MenuDelete);

        MenuAdd.setText("添加");
        MenuUpdate.add(MenuAdd);

        MenuChange.setText("修改");
        MenuUpdate.add(MenuChange);

        jMenuBar1.add(MenuUpdate);

        MenuQuery.setText("查询");

        MenuQueryall.setText("查询全表");
        MenuQuery.add(MenuQueryall);

        jMenuBar1.add(MenuQuery);

        MenuAbout.setText("关于");

        Aboutme.setText("关于作者");
        MenuAbout.add(Aboutme);

        jMenuBar1.add(MenuAbout);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 155, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 746, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane1)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane2)
                .addContainerGap())
        );
        //displayResultSet(business.Query2());
        pack();

        this.setTitle("MyAccessViewer");
    }// </editor-fold>                        
    
    private void MenuExitActionPerformed(java.awt.event.ActionEvent evt) {                                         
        // TODO add your handling code here:
    }                                        
	/**
	 * AddEvent
	 */
    private void addEvents() {
	MenuQueryall
	.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
		UpdateDialog updateDialog = new UpdateDialog(4, MyMainFrame.this);
		updateDialog.setTitle("查询全表");
		updateDialog.setVisible(true);
		}
	});

		// Add
	MenuAdd.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
		UpdateDialog updateDialog = new UpdateDialog(1, MyMainFrame.this);
		updateDialog.setTitle("添加");
		updateDialog.setVisible(true);
		}
	});
		// Change
	MenuChange.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
                UpdateDialog updateDialog = new UpdateDialog(3, MyMainFrame.this);
                updateDialog.setTitle("修改");
                updateDialog.setVisible(true);
                }
	});
		// Delete
	MenuDelete.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
                UpdateDialog updateDialog = new UpdateDialog(2, MyMainFrame.this);
                updateDialog.setTitle("删除");
                updateDialog.setVisible(true);
		}
	});
		// Exit
	MenuExit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
                System.exit(0);
		}
	});
		// Aboutme
	Aboutme.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
            java.awt.EventQueue.invokeLater(new Runnable() {
                public void run() {
                    new AboutMe().setVisible(true);
            }
        });
			}
		});
	
	jTree1.addMouseListener(new MouseAdapter() {
        @Override
        public void mouseClicked(MouseEvent e) {
            // 如果在这棵树上点击了2次,即双击
            if (e.getSource() == jTree1 && e.getClickCount() == 2) {
                // 按照鼠标点击的坐标点获取路径
                TreePath selPath = jTree1.getPathForLocation(e.getX(), e.getY());
                if (selPath != null)// 谨防空指针异常!双击空白处是会这样
                {
                    //System.out.println(selPath);// 输出路径看一下
                    // 获取这个路径上的最后一个组件,也就是双击的地方
                    DefaultMutableTreeNode node = (DefaultMutableTreeNode) selPath.getLastPathComponent();
                    //System.out.println(node.toString());// 输出这个组件toString()的字符串看一下
                    tmp=node.toString();
                    displayResultSet(business.Query2(node.toString()));
                }
            }

        }
    });

	}
    /**
     * @param args the command line arguments
     */

    	public void displayResultSet(ResultSet rs) {
		boolean moreRecords = false;
		try {
			moreRecords = rs.next();
		} catch (SQLException e1) {
			e1.printStackTrace();
		} 
		if (!moreRecords) {
			JOptionPane.showMessageDialog(null, "结果集中无记录", "无记录",
					JOptionPane.INFORMATION_MESSAGE);
			return;
		}

		Vector<Vector<String>> rows = new Vector<Vector<String>>();
		Vector<String> columnHeads = new Vector<String>();
		try {
			ResultSetMetaData rsmd = rs.getMetaData();  // 获得rs结果集中列属性信息
			for (int i = 1; i <= rsmd.getColumnCount(); ++i)
				columnHeads.addElement(rsmd.getColumnName(i)); // 获得列名(将列名存放至向量columnHeads)

			do {
				rows.addElement(getNextRow(rs, rsmd));
			} while (rs.next()); // 利用循环获得所有记录
			jTable1 = new JTable(rows, columnHeads);  // 将获得的行列数据信息作为参数重新构造表格视图
                     //   System.out.printf(rows.toString());
			jScrollPane2.setViewportView(jTable1); // 将表格视图加入
                       
//			jScrollPane2.validate(); 
//			jScrollPane2.repaint();
                        
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

	/**
	 * 获得下一行
	 */
	private Vector<String> getNextRow(ResultSet rs, ResultSetMetaData rsmd)
			throws SQLException {
		Vector<String> currentRow = new Vector<String>(); // 用vector记录
		for (int i = 1; i <= rsmd.getColumnCount(); ++i)
			currentRow.addElement(rs.getString(i)); // 加到vector里
		return currentRow; // 返回
	}
    // Variables declaration - do not modify                     
                   
    private javax.swing.JMenuItem Aboutme;
    private javax.swing.JMenu MenuAbout;
    private javax.swing.JMenuItem MenuAdd;
    private javax.swing.JMenuItem MenuChange;
    private javax.swing.JMenuItem MenuDelete;
    private javax.swing.JMenuItem MenuExit;
    private javax.swing.JMenu MenuQuery;
    private javax.swing.JMenuItem MenuQueryall;
    private javax.swing.JMenu MenuSystem;
    private javax.swing.JMenu MenuUpdate;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable jTable1;
    private javax.swing.JTree jTree1;
    private String tmp;

    // End of variables declaration                   
}