USE master
GO

IF DB_ID('QLCB') IS NOT NULL
	DROP DATABASE QLCB

CREATE DATABASE QLCB
GO

USE QLCB
GO

CREATE TABLE PHANCONG 
(
	MANV nvarchar (15)  NOT NULL ,
	NGAYDI smalldatetime NOT NULL ,
	MACB nvarchar (3)  NOT NULL 
) 

CREATE TABLE CHUYENBAY 

(
	MACB nvarchar (3)  NOT NULL ,
	SBDI nvarchar (3)  NULL ,
	SBDEN nvarchar (3)  NULL ,
	GIODI smalldatetime NULL ,
	GIODEN smalldatetime NULL 
)

CREATE TABLE KHACHHANG 
(
	MAKH nvarchar (15) NOT NULL,
	TEN nvarchar (15)  NULL ,
	DCHI nvarchar (50)  NULL ,
	DTHOAI nvarchar (15)  NULL 
) 

CREATE TABLE DATCHO 
(
	MAKH nvarchar (15)  NOT NULL ,
	NGAYDI smalldatetime NOT NULL ,
	MACB nvarchar (3)  NOT NULL 
) 

CREATE TABLE KHANANG 
(
	MANV nvarchar (15)  NOT NULL ,
	MALOAI nvarchar (15)  NOT NULL 
) 

CREATE TABLE LICHBAY 
(
	NGAYDI smalldatetime NOT NULL ,
	MACB nvarchar (3)  NOT NULL ,
	SOHIEU smallint NULL ,
	MALOAI nvarchar (15)  NULL 
) 

CREATE TABLE LOAIMB 
(
	HANGSX nvarchar (15)  NULL ,
	MALOAI nvarchar (15)  NOT NULL 
) 

CREATE TABLE MAYBAY 
(
	SOHIEU smallint NOT NULL ,
	MALOAI nvarchar (15)  NOT NULL 
) 

CREATE TABLE NHANVIEN 
(
	MANV nvarchar (15)  NOT NULL ,
	TEN nvarchar (15)  NULL ,
	DCHI nvarchar (50)  NULL ,
	DTHOAI nvarchar (15)  NULL ,
	LUONG float NULL ,
	LOAINV bit NULL 
)