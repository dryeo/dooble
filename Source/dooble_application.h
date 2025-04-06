/*
** Copyright (c) 2008 - present, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from Dooble without specific prior written permission.
**
** DOOBLE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** DOOBLE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef dooble_application_h
#define dooble_application_h

#include <QApplication>
#include <QFont>

class QTranslator;
class dooble;

class dooble_application: public QApplication
{
  Q_OBJECT

 public:
  static QHash<QString, QColor> s_theme_colors;
  dooble_application(int &argc, char **argv);
  QFont default_font(void) const;
  QString style_name(void) const;
  bool application_locked(void) const;
  void install_translator(void);
  void set_application_locked(bool state);
  static void prepare_theme_colors(void);

 private:
  QFont m_default_font;
  QTranslator *m_translator;
  bool m_application_locked;

 private slots:
  void slot_application_locked(bool state, dooble *d);

 signals:
  void address_widget_populated(void);
  void application_locked(bool state, dooble *d);
  void cookies_cleared(void);
  void decreased_page_brightness(bool state);
  void dooble_credentials_authenticated(bool state);
  void favorites_cleared(void);
  void favorites_sorted(void);
  void history_cleared(void);
  void javascript_scripts_cleared(void);
  void status_bar_visible(bool state);
};

#endif
