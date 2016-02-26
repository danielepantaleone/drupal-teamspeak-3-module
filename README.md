Drupal 7 Teamspeak 3 Module
===========================

## Description

This module provides a simple Teamspeak 3 server web viewer rendered into a block<br />
It's compatible only with **Drupal 7.x** core: no Drupal 6 version will be implemented since there are already other modules that offer the same functionality and which are compatible with Drupal 6.x core.

## Installation

As usual for Drupal 7.x modules you can install this one in 2 ways:

* Download the repo as **.zip** archive and install it using the Drupal 7.x built in Update Manager.
* Download the repo and unpack the archive in **sites/all/modules/** in your Drupal 7 installation.

## Configuration

Navigate to: **Admin** > **Configuration** > **Teamspeak** > **Settings** (*admin/config/teamspeak/settings* if you have clean URL enabled) and fill in the configuration form with correct data. The module provide an internal block cache system which is independent from the Drupal 7 block cache. In the **Advanced** category of configuration form, you can tune your cache preferences, together with the Teamspeak 3 server connection timeout.
