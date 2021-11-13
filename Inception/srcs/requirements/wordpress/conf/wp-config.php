<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wp' );

/** MySQL database username */
define( 'DB_USER', 'wp' );

/** MySQL database password */
define( 'DB_PASSWORD', 'secret' );

/** MySQL hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'lS&T,RJCSqq@};#JJW;9Q%8J3VZceOoh3Kq+ZGEfZ&C$Ffx>)c;S]+w#=aNb@!Hy' );
define( 'SECURE_AUTH_KEY',  '#y)yUd7YG?hEfWv:IDz|0HTbVBz.%6b~9onJYKM*`x|2dL/H:%!4rVf&NhK2R[/E' );
define( 'LOGGED_IN_KEY',    ']P#)g(cBDHP L%N$yUBUlT)oHt1.NLBv]HkYl2qVPNe7!rmpzAtJ4wl_sF8iIXjY' );
define( 'NONCE_KEY',        'JU@d K+5UC[k_3*<^=(PM eTA&9Ikan5mU<OAsUVI@`b5RsbzH#.O)]uh>Rcm{3_' );
define( 'AUTH_SALT',        'qF~K77Km(.(ZSjJpp0,,qn2?v8L&UG!WU8H@KR:k|E6IK?>6,hw^?4^s.>C73SSE' );
define( 'SECURE_AUTH_SALT', 'I S-FTl7<!l&F1uMjvmzs;:~TWlJ[})x.jMx<Q#0Vo=)n9?(1K,rmm,M]jv4K.wt' );
define( 'LOGGED_IN_SALT',   'm1XUCAsv-mU!c$b|p=ZE1| CcH*?@d#-;bJeGz77x!Qw8(zv)$[s[!Mxj1@luJ@|' );
define( 'NONCE_SALT',       'NiJ7@`]gOx;Khq:>RcN8AE!5J}!n(3W18Jw7Ea8kKCsT`|+0Sx9-bkbA+S+Sx;|/' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
