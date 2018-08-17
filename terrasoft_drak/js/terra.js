(function ($) {
  Drupal.behaviors.theming_workservic = {
    attach: function (context, settings) {
      $('.wrapper-terra .form-type-select .form-select').styler();
    }
  };
})(jQuery);