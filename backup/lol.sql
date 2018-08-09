-- --------------------------------------------------------
-- Host:                         skyser.kr
-- Server version:               10.2.16-MariaDB-10.2.16+maria~xenial-log - mariadb.org binary distribution
-- Server OS:                    debian-linux-gnu
-- HeidiSQL Version:             9.5.0.5196
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Dumping database structure for lol
CREATE DATABASE IF NOT EXISTS `lol` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `lol`;

-- Dumping structure for table lol.match
CREATE TABLE IF NOT EXISTS `match` (
  `matchId` bigint(20) NOT NULL,
  `version` char(50) NOT NULL,
  UNIQUE KEY `matchId` (`matchId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Data exporting was unselected.
-- Dumping structure for table lol.user
CREATE TABLE IF NOT EXISTS `user` (
  `region` char(50) NOT NULL,
  `account_id` bigint(20) NOT NULL,
  `summoner_id` bigint(20) NOT NULL,
  `summoner_name` char(50) NOT NULL,
  `register_date` datetime NOT NULL,
  `update_date` datetime NOT NULL,
  UNIQUE KEY `region_account_id` (`region`,`account_id`),
  UNIQUE KEY `region_summoner_id` (`region`,`summoner_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Data exporting was unselected.
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
