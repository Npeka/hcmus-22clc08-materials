USE [master]
GO
if db_id('QLTSinh') is not null
	drop database QLTSinh
go
/****** Object:  Database [QLTS]    Script Date: 4/15/2021 7:52:36 AM ******/
CREATE DATABASE [QLTSinh] 
GO
USE [QLTSinh]
GO
/****** Object:  Table [dbo].[BuoiThi]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BuoiThi](
	[MaBT] [char](20) NOT NULL,
	[MaMon] [char](20) NULL,
	[MaKhoi] [char](20) NULL,
	[TDBatDau] [datetime] NOT NULL,
	[ThoiGianThi] [int] NOT NULL,
 CONSTRAINT [pk_BuoiThi] PRIMARY KEY CLUSTERED 
(
	[MaBT] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[DiaDiemThi]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DiaDiemThi](
	[MaDDT] [char](20) NOT NULL,
	[TenDDT] [varchar](50) NULL,
	[DiaChi] [varchar](50) NULL,
 CONSTRAINT [pk_DDT] PRIMARY KEY CLUSTERED 
(
	[MaDDT] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[DuThi]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DuThi](
	[SBD] [char](20) NOT NULL,
	[MaBT] [char](20) NOT NULL,
	[Diem] [float] NULL,
 CONSTRAINT [pk_DuThi] PRIMARY KEY CLUSTERED 
(
	[SBD] ASC,
	[MaBT] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Khoi]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Khoi](
	[MaKhoi] [char](20) NOT NULL,
	[TenKhoi] [varchar](50) NULL,
 CONSTRAINT [pk_Khoi] PRIMARY KEY CLUSTERED 
(
	[MaKhoi] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Khoi_Mon]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Khoi_Mon](
	[MaKhoi] [char](20) NOT NULL,
	[MaMon] [char](20) NOT NULL,
 CONSTRAINT [pk_Khoi_Mon] PRIMARY KEY CLUSTERED 
(
	[MaKhoi] ASC,
	[MaMon] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[MonThi]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MonThi](
	[MaMT] [char](20) NOT NULL,
	[TenMT] [varchar](50) NULL,
 CONSTRAINT [pk_MonThi] PRIMARY KEY CLUSTERED 
(
	[MaMT] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Nganh]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Nganh](
	[MaNganh] [char](20) NOT NULL,
	[TenNganh] [varchar](50) NULL,
	[ChiTieu] [int] NULL,
 CONSTRAINT [pk_Nganh] PRIMARY KEY CLUSTERED 
(
	[MaNganh] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Nganh_Khoi]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Nganh_Khoi](
	[MaNganh] [char](20) NOT NULL,
	[MaKhoi] [char](20) NOT NULL,
	[DiemChuan] [float] NULL,
 CONSTRAINT [pk_NganhKhoi] PRIMARY KEY CLUSTERED 
(
	[MaNganh] ASC,
	[MaKhoi] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ThiSinh]    Script Date: 4/15/2021 7:52:36 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ThiSinh](
	[SBD] [char](20) NOT NULL,
	[HoTen] [varchar](50) NULL,
	[NgaySinh] [datetime] NULL,
	[HoKhau] [varchar](50) NULL,
	[NoiHocPTTH] [varchar](50) NULL,
	[Nganh] [char](20) NULL,
	[Khoi] [char](20) NULL,
	[DDiemThi] [char](20) NULL,
	[Phong] [varchar](50) NULL,
 CONSTRAINT [pk_ThiSinh] PRIMARY KEY CLUSTERED 
(
	[SBD] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[BuoiThi] ([MaBT], [MaMon], [MaKhoi], [TDBatDau], [ThoiGianThi]) VALUES (N'0401                ', N'T                   ', N'A                   ', CAST(N'2004-07-05T08:00:00.000' AS DateTime), 180)
GO
INSERT [dbo].[BuoiThi] ([MaBT], [MaMon], [MaKhoi], [TDBatDau], [ThoiGianThi]) VALUES (N'0402                ', N'L                   ', N'A                   ', CAST(N'2004-07-05T13:30:00.000' AS DateTime), 180)
GO
INSERT [dbo].[BuoiThi] ([MaBT], [MaMon], [MaKhoi], [TDBatDau], [ThoiGianThi]) VALUES (N'0403                ', N'H                   ', N'A                   ', CAST(N'2004-07-06T08:00:00.000' AS DateTime), 180)
GO
INSERT [dbo].[BuoiThi] ([MaBT], [MaMon], [MaKhoi], [TDBatDau], [ThoiGianThi]) VALUES (N'0404                ', N'T                   ', N'B                   ', CAST(N'2004-07-10T08:00:00.000' AS DateTime), 180)
GO
INSERT [dbo].[BuoiThi] ([MaBT], [MaMon], [MaKhoi], [TDBatDau], [ThoiGianThi]) VALUES (N'0405                ', N'H                   ', N'B                   ', CAST(N'2004-07-10T13:30:00.000' AS DateTime), 180)
GO
INSERT [dbo].[BuoiThi] ([MaBT], [MaMon], [MaKhoi], [TDBatDau], [ThoiGianThi]) VALUES (N'0406                ', N'S                   ', N'B                   ', CAST(N'2004-07-11T13:30:00.000' AS DateTime), 180)
GO
INSERT [dbo].[DiaDiemThi] ([MaDDT], [TenDDT], [DiaChi]) VALUES (N'C001                ', N'Truong THPT Bui Huu Nghia', N'55 CMT8,  Q Binh Thuy,  TP Can Tho')
GO
INSERT [dbo].[DiaDiemThi] ([MaDDT], [TenDDT], [DiaChi]) VALUES (N'H001                ', N'Truong DH KHTN', N'227 Nguyen Van Cu,  Q5,  TP HCM')
GO
INSERT [dbo].[DiaDiemThi] ([MaDDT], [TenDDT], [DiaChi]) VALUES (N'H002                ', N'Truong THCS BC Bach Dang', N'386/42 Le Van Si,  Q3,  TP HCM')
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.00075         ', N'0401                ', 6.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.00075         ', N'0402                ', 7)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.00075         ', N'0403                ', 4.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.00779         ', N'0401                ', 8.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.00779         ', N'0402                ', 7)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.00779         ', N'0403                ', 9)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.01215         ', N'0401                ', 7.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.01215         ', N'0402                ', 8)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.01215         ', N'0403                ', 5.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.01395         ', N'0401                ', 9)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.01395         ', N'0402                ', 8)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.03709         ', N'0401                ', 9)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.03709         ', N'0402                ', 6)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.03709         ', N'0403                ', 10)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.06715         ', N'0401                ', 1.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.06765         ', N'0401                ', 5.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.06765         ', N'0402                ', 4.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.06765         ', N'0403                ', 7)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.12454         ', N'0401                ', 8)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.12454         ', N'0402                ', 5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.A.12454         ', N'0403                ', 9)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.B.00024         ', N'0404                ', 9)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.B.00024         ', N'0405                ', 9.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.B.00024         ', N'0406                ', 8)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.B.00627         ', N'0404                ', 3.5)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.B.04729         ', N'0404                ', 6)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.B.04729         ', N'0405                ', 4)
GO
INSERT [dbo].[DuThi] ([SBD], [MaBT], [Diem]) VALUES (N'QST.B.04729         ', N'0406                ', 7)
GO
INSERT [dbo].[Khoi] ([MaKhoi], [TenKhoi]) VALUES (N'A                   ', N'Khoi A')
GO
INSERT [dbo].[Khoi] ([MaKhoi], [TenKhoi]) VALUES (N'B                   ', N'Khoi B')
GO
INSERT [dbo].[Khoi_Mon] ([MaKhoi], [MaMon]) VALUES (N'A                   ', N'H                   ')
GO
INSERT [dbo].[Khoi_Mon] ([MaKhoi], [MaMon]) VALUES (N'A                   ', N'L                   ')
GO
INSERT [dbo].[Khoi_Mon] ([MaKhoi], [MaMon]) VALUES (N'A                   ', N'T                   ')
GO
INSERT [dbo].[Khoi_Mon] ([MaKhoi], [MaMon]) VALUES (N'B                   ', N'H                   ')
GO
INSERT [dbo].[Khoi_Mon] ([MaKhoi], [MaMon]) VALUES (N'B                   ', N'S                   ')
GO
INSERT [dbo].[Khoi_Mon] ([MaKhoi], [MaMon]) VALUES (N'B                   ', N'T                   ')
GO
INSERT [dbo].[MonThi] ([MaMT], [TenMT]) VALUES (N'H                   ', N'Hoa Hoc')
GO
INSERT [dbo].[MonThi] ([MaMT], [TenMT]) VALUES (N'L                   ', N'Vat Ly')
GO
INSERT [dbo].[MonThi] ([MaMT], [TenMT]) VALUES (N'S                   ', N'Sinh Hoc')
GO
INSERT [dbo].[MonThi] ([MaMT], [TenMT]) VALUES (N'T                   ', N'Toan')
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [ChiTieu]) VALUES (N'101                 ', N'Toan - Tin hoc', 300)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [ChiTieu]) VALUES (N'107                 ', N'Cong nghe Thong tin', 480)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [ChiTieu]) VALUES (N'205                 ', N'Khoa hoc Moi truong', 150)
GO
INSERT [dbo].[Nganh] ([MaNganh], [TenNganh], [ChiTieu]) VALUES (N'312                 ', N'Cong nghe Sinh hoc', 170)
GO
INSERT [dbo].[Nganh_Khoi] ([MaNganh], [MaKhoi], [DiemChuan]) VALUES (N'101                 ', N'A                   ', 17.5)
GO
INSERT [dbo].[Nganh_Khoi] ([MaNganh], [MaKhoi], [DiemChuan]) VALUES (N'107                 ', N'A                   ', 21)
GO
INSERT [dbo].[Nganh_Khoi] ([MaNganh], [MaKhoi], [DiemChuan]) VALUES (N'205                 ', N'A                   ', 18)
GO
INSERT [dbo].[Nganh_Khoi] ([MaNganh], [MaKhoi], [DiemChuan]) VALUES (N'205                 ', N'B                   ', 22.5)
GO
INSERT [dbo].[Nganh_Khoi] ([MaNganh], [MaKhoi], [DiemChuan]) VALUES (N'312                 ', N'A                   ', 21)
GO
INSERT [dbo].[Nganh_Khoi] ([MaNganh], [MaKhoi], [DiemChuan]) VALUES (N'312                 ', N'B                   ', 24.5)
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.00071         ', N'Phan Thanh Duy', NULL, N'H Long Ho - Tinh Vinh Long', N'THPT chuyen NBK,  Tinh Vinh Long', N'107                 ', N'A                   ', NULL, NULL)
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.00073         ', N'La Kim Anh', NULL, N'Quan 5 - TP HCM', N'THPT Hung Vuong TPHCM', N'107                 ', N'A                   ', NULL, NULL)
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.00075         ', N'La Kim Anh', CAST(N'1985-03-29T00:00:00.000' AS DateTime), N'Quan 5 - TP HCM', N'THPT Hung Vuong TPHCM', N'101                 ', N'A                   ', N'H001                ', N'001')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.00627         ', N'Le Bao Chau', CAST(N'1986-09-24T00:00:00.000' AS DateTime), N'Quan 1 - TP HCM', N'THPT Bui Thi Xuan TPHCM', N'107                 ', N'A                   ', N'H001                ', N'056')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.00779         ', N'Le Minh Cuong', CAST(N'1986-01-02T00:00:00.000' AS DateTime), N'Quan 10 - TP HCM', N'THPT Le Hong Phong TPHCM', N'107                 ', N'A                   ', N'H001                ', N'056')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.01215         ', N'Nguyen Duy Dat', CAST(N'1985-01-20T00:00:00.000' AS DateTime), N'Quan Binh Thanh - TP HCM', N'THPT Ngo Quyen, Tinh Dong Nai', N'205                 ', N'A                   ', N'H002                ', N'018')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.01395         ', N'Le Huy Giang', CAST(N'1985-10-01T00:00:00.000' AS DateTime), N'TX Tan An - Tinh Long An', N'THPT Tan An,  Tinh Long An', N'101                 ', N'A                   ', N'C001                ', N'008')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.01396         ', N'Le Huy Giang', CAST(N'1985-10-01T00:00:00.000' AS DateTime), N'TX Tan An - Tinh Long An', N'THPT Tan An,  Tinh Long An', N'107                 ', N'A                   ', N'C001                ', N'008')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.01397         ', N'Nguyen Van A', CAST(N'1985-10-01T00:00:00.000' AS DateTime), N'TX Tan An - Tinh Long An', N'THPT Tan An,  Tinh Long An', N'107                 ', N'A                   ', N'C001                ', N'008')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.03709         ', N'Pham Thi Hong Nhung', CAST(N'1984-12-08T00:00:00.000' AS DateTime), N'H Thanh Phu - Tinh Ben Tre', N'THPT Tam Phuoc,  Tinh Dong Nai', N'107                 ', N'A                   ', N'C001                ', N'048')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.06715         ', N'Phan Thanh Duy', CAST(N'1986-11-20T00:00:00.000' AS DateTime), N'H Long Ho - Tinh Vinh Long', N'THPT chuyen NBK,  Tinh Vinh Long', N'312                 ', N'A                   ', N'C001                ', N'217')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.06765         ', N'Pham Thi My Hanh', CAST(N'1985-04-18T00:00:00.000' AS DateTime), N'H Cang Long - Tinh Tra Vinh', N'THPT DTNT Tra Vinh,  Tinh Tra Vinh', N'312                 ', N'A                   ', N'C001                ', N'017')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.A.12454         ', N'Dang Thi Thuy Vy', CAST(N'1983-01-08T00:00:00.000' AS DateTime), N'Quan Ninh Kieu - TP Can Tho', N'THPT BC Ng Viet Dung,  TP Can Tho', N'205                 ', N'A                   ', N'C001                ', N'343')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.B.00024         ', N'Nguyen Thi Thuy An', CAST(N'1986-03-07T00:00:00.000' AS DateTime), N'Quan Binh Thanh - TP HCM', N'THPT Gia Dinh TPHCM', N'205                 ', N'B                   ', N'H002                ', N'027')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.B.00073         ', N'La Kim Anh', NULL, N'Quan 5 - TP HCM', N'THPT Hung Vuong TPHCM', N'205                 ', N'B                   ', NULL, NULL)
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.B.00627         ', N'Le Bao Chau', CAST(N'1986-09-24T00:00:00.000' AS DateTime), N'Quan 1 - TP HCM', N'THPT Bui Thi Xuan TPHCM', N'205                 ', N'B                   ', N'H001                ', N'056')
GO
INSERT [dbo].[ThiSinh] ([SBD], [HoTen], [NgaySinh], [HoKhau], [NoiHocPTTH], [Nganh], [Khoi], [DDiemThi], [Phong]) VALUES (N'QST.B.04729         ', N'Phan Van Thanh', CAST(N'1982-11-09T00:00:00.000' AS DateTime), N'H Can Gio - TP HCM', N'THPT Binh Khanh TPHCM', N'312                 ', N'B                   ', N'H002                ', N'007')
GO
ALTER TABLE [dbo].[BuoiThi]  WITH CHECK ADD  CONSTRAINT [fk_BT_KM] FOREIGN KEY([MaKhoi], [MaMon])
REFERENCES [dbo].[Khoi_Mon] ([MaKhoi], [MaMon])
GO
ALTER TABLE [dbo].[BuoiThi] CHECK CONSTRAINT [fk_BT_KM]
GO
ALTER TABLE [dbo].[DuThi]  WITH CHECK ADD  CONSTRAINT [fk_DT_BT] FOREIGN KEY([MaBT])
REFERENCES [dbo].[BuoiThi] ([MaBT])
GO
ALTER TABLE [dbo].[DuThi] CHECK CONSTRAINT [fk_DT_BT]
GO
ALTER TABLE [dbo].[DuThi]  WITH CHECK ADD  CONSTRAINT [fk_DT_TS] FOREIGN KEY([SBD])
REFERENCES [dbo].[ThiSinh] ([SBD])
GO
ALTER TABLE [dbo].[DuThi] CHECK CONSTRAINT [fk_DT_TS]
GO
ALTER TABLE [dbo].[Khoi_Mon]  WITH CHECK ADD  CONSTRAINT [fk_KM_Khoi] FOREIGN KEY([MaKhoi])
REFERENCES [dbo].[Khoi] ([MaKhoi])
GO
ALTER TABLE [dbo].[Khoi_Mon] CHECK CONSTRAINT [fk_KM_Khoi]
GO
ALTER TABLE [dbo].[Khoi_Mon]  WITH CHECK ADD  CONSTRAINT [fk_KM_MT] FOREIGN KEY([MaMon])
REFERENCES [dbo].[MonThi] ([MaMT])
GO
ALTER TABLE [dbo].[Khoi_Mon] CHECK CONSTRAINT [fk_KM_MT]
GO
ALTER TABLE [dbo].[Nganh_Khoi]  WITH CHECK ADD  CONSTRAINT [fk_NK_Khoi] FOREIGN KEY([MaKhoi])
REFERENCES [dbo].[Khoi] ([MaKhoi])
GO
ALTER TABLE [dbo].[Nganh_Khoi] CHECK CONSTRAINT [fk_NK_Khoi]
GO
ALTER TABLE [dbo].[Nganh_Khoi]  WITH CHECK ADD  CONSTRAINT [fk_NK_Nganh] FOREIGN KEY([MaNganh])
REFERENCES [dbo].[Nganh] ([MaNganh])
GO
ALTER TABLE [dbo].[Nganh_Khoi] CHECK CONSTRAINT [fk_NK_Nganh]
GO
ALTER TABLE [dbo].[ThiSinh]  WITH CHECK ADD  CONSTRAINT [fk_TS_DDT] FOREIGN KEY([DDiemThi])
REFERENCES [dbo].[DiaDiemThi] ([MaDDT])
GO
ALTER TABLE [dbo].[ThiSinh] CHECK CONSTRAINT [fk_TS_DDT]
GO
ALTER TABLE [dbo].[ThiSinh]  WITH CHECK ADD  CONSTRAINT [fk_TS_NK] FOREIGN KEY([Nganh], [Khoi])
REFERENCES [dbo].[Nganh_Khoi] ([MaNganh], [MaKhoi])
GO
ALTER TABLE [dbo].[ThiSinh] CHECK CONSTRAINT [fk_TS_NK]
GO

select * from diadiemthi
select * from duthi
select * from khoi
select * from Khoi_Mon
select * from MonThi
select * from Nganh_Khoi
select * from Nganh
select * from ThiSinh
select * from BuoiThi